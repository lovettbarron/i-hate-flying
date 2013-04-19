#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    cabin = new Cabin();
    
    
	ofSetVerticalSync(true);
	ofEnableSmoothing();
	glEnable(GL_DEPTH_TEST);

    light.setAmbientColor(ofColor(0, 0, 0));
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);
    ofPushMatrix();
    
	ofPushStyle();
	light.enable();
	light.setPosition(2000,0,0);
    
    cabin->draw();
    
	light.disable();
	ofDisableLighting();

    
    
    ofSetColor(255);
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