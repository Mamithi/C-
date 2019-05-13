#include <gst/gst.h>

int main(int argc, char** argv) 
{ 
    gst_init (&argc,&argv); 

    GstElement *bin = gst_pipeline_new(NULL); 
    g_assert(bin); 

    GstElement *src = gst_element_factory_make("rtspsrc", NULL); 
    g_assert(src); 
    g_object_set(src, "location", "rtsp://admin:pangani123@192.168.1.240:554/LiveMedia/ch1/Media1", NULL); 

    GstElement *sink = gst_element_factory_make("fakesink", NULL); 
    g_assert(sink); 

    gst_bin_add_many(GST_BIN(bin), src, sink, NULL); 
    gst_element_link_many(src, sink, NULL); 

    gst_element_set_state(GST_ELEMENT(bin), GST_STATE_PLAYING); 

    while(1) 
        ; 
} 