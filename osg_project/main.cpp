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
    viewer.setCameraManipulator(new osgGA::TrackballManipulator());

    // Load a model
//    osg::Node* modelNode = osgDB::readNodeFile("../osg_files/cow.osg");
    osg::Node* modelNode = osgDB::readNodeFile("../osg_files/lz.osgt");
    if(!modelNode) {
        cout << "Could not find the model" << endl;
        return EXIT_FAILURE;
    }

    osg::Group* root = new osg::Group();
    root->addChild(modelNode);

    viewer.setSceneData(root);
    viewer.realize();

    while(!viewer.done()) {
        viewer.frame();
    }


    cout << "Hello, World!" << std::endl;
    return 0;
}