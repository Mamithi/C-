#include <gst/gst.h>

int main(int argc, char** argv) {
    GstElement *pipeline, *source, *sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;

    gst_init(&argc, &argv);

    source = gst_element_factory_make("rtspsrc", "source");
    sink = gst_element_factory_make("rtph264depay", "sink");
    g_object_set(source, "location", "rtsp://admin:pangani123@192.168.1.240:554/LiveMedia/ch1/Media1", NULL);

    pipeline = gst_pipeline_new("rtsp-pipeline");


    if(!pipeline || !source || !sink) {
        g_printerr("Elements could not be linked.\n");
        return -1;
    }

    gst_bin_add_many(GST_BIN(pipeline), source, sink, NULL);
    if(gst_element_link(source, sink) != TRUE){
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    g_print("Hello, Its all good here");
    return 0;

}