#include <iostream>
#include <osg/Group>
#include <osg/Node>
#include <osg/PositionAttitudeTransform>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>


using namespace std;

int main() {
    osg::Group *root = new osg::Group();
    osg::Geode *pyramidGeode = new osg::Geode();
    osg::Geometry *pyramidGeometry = new osg::Geometry();

    pyramidGeode->addDrawable(pyramidGeometry);
    root->addChild(pyramidGeode);

    osg::Vec3Array *pyramidVertices = new osg::Vec3Array;
    pyramidVertices->push_back(osg::Vec3(0, 0, 0));
    pyramidVertices->push_back(osg::Vec3(10, 0, 0));
    pyramidVertices->push_back(osg::Vec3(10, 10, 0));
    pyramidVertices->push_back(osg::Vec3(0, 10, 0));
    pyramidVertices->push_back(osg::Vec3(0, 10, 0));
    pyramidVertices->push_back(osg::Vec3(5, 5, 10));

    pyramidGeometry->setVertexArray(pyramidVertices);

    osg::DrawElementsUInt *pyramidBase = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    pyramidBase->push_back(3);
    pyramidBase->push_back(2);
    pyramidBase->push_back(1);
    pyramidBase->push_back(0);
    pyramidGeometry->addPrimitiveSet(pyramidBase);

    osg::DrawElementsUInt *pyramidFaceOne = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
    pyramidFaceOne->push_back(0);
    pyramidFaceOne->push_back(1);
    pyramidFaceOne->push_back(4);
    pyramidGeometry->addPrimitiveSet(pyramidFaceOne);

    osg::DrawElementsUInt *pyramidFaceTwo = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
    pyramidFaceTwo->push_back(1);
    pyramidFaceTwo->push_back(2);
    pyramidFaceTwo->push_back(4);
    pyramidGeometry->addPrimitiveSet(pyramidFaceTwo);

    osg::DrawElementsUInt *pyramidFaceThree = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
    pyramidFaceThree->push_back(2);
    pyramidFaceThree->push_back(3);
    pyramidFaceThree->push_back(4);
    pyramidGeometry->addPrimitiveSet(pyramidFaceThree);

    osg::DrawElementsUInt *pyramidFaceFour = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
    pyramidFaceFour->push_back(3);
    pyramidFaceFour->push_back(0);
    pyramidFaceFour->push_back(4);
    pyramidGeometry->addPrimitiveSet(pyramidFaceFour);

    osg::Vec4Array *colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
    colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
    colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
    colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
    colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));

    pyramidGeometry->setColorArray(colors);
    pyramidGeometry->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE_SET);


    // Declare and initialize a transform node.
    osg::PositionAttitudeTransform *pyramidTwoXForm = new osg::PositionAttitudeTransform();

    root->addChild(pyramidTwoXForm);
    pyramidTwoXForm->addChild(pyramidGeode);

    osg::Vec3 pyramidTwoPosition(15, 0, 0);
    pyramidTwoXForm->setPosition(pyramidTwoPosition);

    root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);


    osgViewer::Viewer viewer;
    viewer.setSceneData(root);
    viewer.setCameraManipulator(new osgGA::TrackballManipulator());
    viewer.realize();

    while(!viewer.done()) {
        viewer.frame();
    }






    cout << "Hello, World!" << endl;
    return 0;
}