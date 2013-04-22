#include "testApp.h"


GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};


//--------------------------------------------------------------
void testApp::setup(){
    audio = new AudioControl();
    cabin = new Cabin(*audio);
    pulse = new PulseControl();

    setupPanel();
    
	ofSetVerticalSync(true);
	ofEnableSmoothing();
	ofEnableLighting();
    cam.setup();
    cam.loadCameraPosition();

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
    
    ofAddListener(GameEvent::events, this, &testApp::eventControl);
}

//--------------------------------------------------------------
void testApp::update(){
    pulse->update();
    cabin->update();
    audio->update();
    
    if(panel.getValueB("playTimeline"))
        timeline.togglePlay();
    
    if(panel.getValueB("showTimeline"))
        timeline.toggleShow();
    
    if(panel.hasValueChanged("seatbelts"))
        cabin->setSeatbelt(panel.getValueB("seatbelts"));
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
    switch(key) {
        case '[':
            cam.saveCameraPosition();
            break;
        case ']':
            cam.loadCameraPosition();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::setupPanel() {
    panelWidth = 300;
    panel.setup(panelWidth, ofGetHeight());
    
    panel.addPanel("Cabin");
    panel.addToggle("showTimeline",false);
    panel.addToggle("playTimeline",false);
    panel.addToggle("seatbelts",false);
    
    panel.addLabel("Lights");
    panel.addSlider("bgColor",255,0,255,true);
    
    panel.addLabel("Windows");
    panel.addSlider("windowDistance", 2, 0,10,false);
    
    panel.addLabel("Seats");
    //angle = panel.getValueI("angle");
    
    panel.setupEvents();
    
  //  ofAddListener(panel.guiCallbackData, this,&testApp::eventDelegate());
}

//--------------------------------------------------------------
void testApp::setupTimeline() {
    
    timeline.setup();
    timeline.setDurationInSeconds(60);
    timeline.setLoopType(OF_LOOP_NORMAL);
    
  //  timeline.addKeyframes("MyCircleRadius", ofRange(0, 200));
}

//--------------------------------------------------------------
void testApp::eventControl(GameEvent &e) {
    
}