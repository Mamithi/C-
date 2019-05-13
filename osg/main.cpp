#include <iostream>
#include <osg/Group>
#include <osg/Node>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>

using  namespace std;

int main() {

    // Create a viewer
    osgViewer::Viewer viewer;
//    viewer.setCameraManipulator(new osgGA::TrackballManipulator());


    cout << "Hello, World!" << std::endl;
    return 0;
}