#include "testApp.h"


GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};


//--------------------------------------------------------------
void testApp::setup(){
    setupPanel();
    setupTimeline();
    audio = new AudioControl();
    cabin = new Cabin(*audio);
    pulse = new PulseControl();
    splash = new SplashScreen();
    
    eventIncrement = 0;
    
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
    
   // ofAddListener(GameEvent::events, this, &testApp::eventControl);
}

//--------------------------------------------------------------
void testApp::update(){
    pulse->update();
    cabin->update();
    audio->update();
    
    if(panel.getValueB("playTimeline"))
        timeline.togglePlay();
    
   // if(panel.getValueB("showTimeline"))
      //  timeline.toggleShow();
    
//    if(panel.hasValueChanged("seatbelts"))
        //cabin->setSeatbelt(panel.getValueB("seatbelts"));
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
    splash->draw();
    if(tlToggle)
        drawTimeline();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch(key) {
//        case '[':
//            cam.saveCameraPosition();
//            break;
//        case ']':
//            cam.loadCameraPosition();
//            break;
        case 't':
            tlToggle = !tlToggle;
            break;
        case '1':
            timelineSelect = 0;
            break;
        case '2':
            timelineSelect = 1;
            break;
        case '3':
            timelineSelect = 2;
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
    tlToggle = false;
    timeline.setup();
    timeline.setName("main");
    timeline.setDurationInSeconds(60);
    timeline.setLoopType(OF_LOOP_NONE);
    timeline.addBangs("event");
    timeline.addCurves("landing");
    timeline.addCurves("stress");

    splashTimeline.setup();
    splashTimeline.setName("intro");
    splashTimeline.setDurationInSeconds(10);
    splashTimeline.setLoopType(OF_LOOP_NONE);
    splashTimeline.addBangs("next");
    splashTimeline.addCurves("fade1");
    splashTimeline.addCurves("fade2");
    
    for(int i = 0; i < 3; i++){
        ofxTimeline* t = new ofxTimeline();
		t->setup();
        t->setSpacebarTogglePlay(false);
        t->setDurationInFrames(400);
        t->addCurves("Sub Timeline " + ofToString(i));
        t->setWidth(ofGetWidth() * .6);
        t->setLoopType(OF_LOOP_NORMAL);
        sublines.push_back(t);
    }
    
    
    
    ofAddListener(timeline.events().bangFired, this, &testApp::eventControl);
  //  timeline.addKeyframes("MyCircleRadius", ofRange(0, 200));
    
    
    splashTimeline.play();
    
}

void testApp::drawTimeline() {
    switch(timelineSelect){
        case 0:
            timeline.draw();
            break;
        case 1:
            splashTimeline.draw();
            break;
        case 2:
            sublines[0]->setOffset(timeline.getBottomLeft() + ofVec2f(0,20));
    
            for(int i = 0; i < sublines.size(); i++){
                if(i != 0){
                    sublines[i]->setOffset(sublines[i-1]->getBottomLeft() + ofVec2f(0, 20));
                }
                sublines[i]->draw();
                
            }
            break;
        default:
            timeline.draw();
            break;
    }
}


//--------------------------------------------------------------
void testApp::eventControl(ofxTLBangEventArgs &e) {
    ofLog() << e.sender->getName();
    if(e.sender->getName() == "main") {
        ofLog() << "Triggering event";
        switch(eventIncrement) {
            case 0:
                //audio->trigger(ANNOUNCE);
                cabin->setSeatbelt(TRUE);
                break;
            case 1:
                audio->trigger(PILOT_LANDING);
                break;
            case 2:
                audio->trigger(LANDINGGEAR);
                break;
            default:
                break;
        }
        eventIncrement += 1;
    } else
    if(e.sender->getName() == "intro") {
        ofLog() << "Next splash screen";
        splash->next();
    }
}