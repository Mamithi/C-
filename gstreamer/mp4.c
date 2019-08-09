#include <gst/gst.h>

typedef struct _CustomData {
    GstElement *pipeline;
    GstElement *source;
    GstElement *rtph264depay_sink;
    GstElement *h264parse_sink;
    GstElement *mp4mux_sink;
    GstElement *filesink;
} CustomData;

static void pad_added_handler(GstElement *src, GstPad *pad, CustomData *data);

int main(int argc, char** argv){
    CustomData data;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;
    gboolean terminate = FALSE;

    // Initialize gstreamer
    gst_init(&argc, &argv);


    // Create the elements
    data.source = gst_element_factory_make("rtspsrc", "source");
    data.rtph264depay_sink = gst_element_factory_make("rtph264depay", "rtph264depay_sink");
    data.h264parse_sink = gst_element_factory_make("h264parse", "h264parse_sink");
    data.mp4mux_sink = gst_element_factory_make("mp4mux", "mp4mux_sink");
    data.filesink = gst_element_factory_make("filesink", "filesink");

    // Create the empty pipeline
    data.pipeline = gst_pipeline_new("rtsp-pipeline");

    if(!data.pipeline || !data.source || !data.rtph264depay_sink || !data.h264parse_sink || !data.mp4mux_sink) {
        g_printerr("Not all elements could be created.\n");
        return -1;
    }

    // Building the pipeline
    gst_bin_add_many(GST_BIN(data.pipeline), data.source, data.rtph264depay_sink, data.h264parse_sink, data.mp4mux_sink, data.filesink, NULL);
    if(gst_element_link_many(data.rtph264depay_sink, data.h264parse_sink, data.mp4mux_sink, data.filesink,  NULL) != TRUE){
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(data.pipeline);
        return -1;
    }

    g_object_set(G_OBJECT(data.source), "location", "rtsp://admin:pangani123@192.168.1.240:554/LiveMedia/ch1/Media1", NULL);
    g_object_set(G_OBJECT(data.filesink), "location", "out", NULL);

    // Connect to the pad-added signal
    g_signal_connect(data.source, "pad-added", G_CALLBACK(pad_added_handler), &data);
    
     // Start playing
    ret = gst_element_set_state(data.pipeline, GST_STATE_PLAYING);
    if(ret == GST_STATE_CHANGE_FAILURE){
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(data.pipeline);
        return -1;
    }

    // Listen to the bus
    bus = gst_element_get_bus(data.pipeline);
    do{
        msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                GST_MESSAGE_STATE_CHANGED | GST_MESSAGE_ERROR | GST_MESSAGE_EOS);
        // parse message
        if(msg != NULL) {
            GError *err;
            gchar *debug_info;

            switch(GST_MESSAGE_TYPE(msg)) {
                case GST_MESSAGE_ERROR:
                    gst_message_parse_error(msg, &err, &debug_info);
                    g_printerr("Error received from element %s: %s\n", GST_OBJECT_NAME(msg->src), err->message);
                    g_printerr("Debuggig information: %s\n", debug_info ? debug_info : "None");
                    g_clear_error(&err);
                    g_free(debug_info);
                    terminate = TRUE;
                    break;
                case GST_MESSAGE_EOS:
                    g_print("End of stream reached.\n");
                    terminate = TRUE;
                    break;
                case GST_MESSAGE_STATE_CHANGED:
                    if(GST_MESSAGE_SRC(msg) == GST_OBJECT(data.pipeline)) {
                        GstState old_state, new_state, pending_state;
                        gst_message_parse_state_changed(msg, &old_state, &new_state, &pending_state);
                        g_print("Pipeline state changed from %s to %s:\n",
                        gst_element_state_get_name(old_state), gst_element_state_get_name(new_state));
                    }
                    break;
                default:
                g_printerr("Unexpecte message received.\n");
                break;
            }
            gst_message_unref(msg);
        }
    } while(!terminate);


    gst_object_unref(bus);
    gst_element_set_state(data.pipeline, GST_STATE_NULL);
    gst_object_unref(data.pipeline);

    g_print("Hello, Its all okay here.\n");
    return 0;
}

static void pad_added_handler(GstElement *src, GstPad *new_pad, CustomData *data) {
    GstPad *sink_pad = gst_element_get_static_pad(data->rtph264depay_sink, "sink");
    GstPadLinkReturn ret;
    GstCaps *new_pad_caps = NULL;
    GstStructure *new_pad_struct = NULL;
    const gchar *new_pad_type = NULL;

    g_print("Received new pad '%s' from '%s':\n", GST_PAD_NAME(new_pad), GST_ELEMENT_NAME(src));


    // if the converter is already linked nothing more to do
    if(gst_pad_is_linked(sink_pad)) {
        g_print("We are already linked, ignoring...\n");
        goto exit;
    }

    // Check the new pad's type
    new_pad_caps = gst_pad_get_current_caps(new_pad);
    new_pad_struct = gst_caps_get_structure(new_pad_caps, 0);
    new_pad_type = gst_structure_get_name(new_pad_struct);

     // Attempt the link
    ret = gst_pad_link(new_pad, sink_pad);
    if(GST_PAD_LINK_FAILED(ret)){
        g_print("Type is '%s' but link failed.\n", new_pad_type);
    } else {
        g_print("Link succeeded (type '%s').\n", new_pad_type);
    }

    exit:
        if(new_pad_caps != NULL) 
            gst_caps_unref(new_pad_caps);

        gst_object_unref(sink_pad);

}