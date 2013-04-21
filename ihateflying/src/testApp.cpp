#include "testApp.h"


GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};


//--------------------------------------------------------------
void testApp::setup(){
    cabin = new Cabin();
    pulse = new PulseControl();

    setupPanel();
    
	ofSetVerticalSync(true);
	ofEnableSmoothing();
	ofEnableLighting();
    cam.setup();

    //some model / light stuff
    glEnable (GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);
    
    /* initialize lighting */
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);
    glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);
    glColorMaterial (GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
    
	glEnable(GL_DEPTH_TEST);

    light.setAmbientColor(ofColor(255, 255, 255));
    light.setSpecularColor(ofColor(255,255,255));
}

//--------------------------------------------------------------
void testApp::update(){
    pulse->update();
//    cam.lookAt(ofVec3f( (ofGetMouseX()/ ofGetWidth()), (ofGetMouseY() / ofGetHeight()),0));
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);
    ofPushMatrix();
    cam.begin();
	ofPushStyle();
	light.enable();
	light.setPosition(21,10,20);
    ofSetColor(0, 0, 0, 255);
    cabin->draw();
    
	light.disable();
	ofDisableLighting();

    
    
    ofSetColor(255);
    cam.end();
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::setupPanel() {
    panelWidth = 300;
    panel.setup(panelWidth, ofGetHeight());
    
    panel.addPanel("Cabin");
    panel.addLabel("Lights");
    panel.addSlider("bgColor",255,0,255,true);
    
    panel.addLabel("Windows");
    
    panel.addLabel("Seats");
    //angle = panel.getValueI("angle");
}