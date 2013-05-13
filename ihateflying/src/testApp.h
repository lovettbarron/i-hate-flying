#pragma once

#include "ofMain.h"
#include "ofxAutoControlPanel.h"
#include "ofxGameCamera.h"
#include "ofxTimeline.h"
#include "pulseControl.h"
#include "audioControl.h"
#include "cabin.h"
#include "event.h"

#define SETPANEL 1

class testApp : public ofBaseApp{

	public:
		void setup();
        void setupPanel();
        void setupTimeline();
        void drawTimeline();
		void update();
		void draw();
    
        void eventControl(ofxTLBangEventArgs &e);

		void keyPressed (int key);
    
    // Bools
    bool tlToggle;
    
    
    // Model
    Cabin * cabin;
    PulseControl * pulse;
    AudioControl * audio;
    ofLight light;
    ofxGameCamera cam;
    ofxAutoControlPanel panel;
    ofxTimeline timeline;
    vector<ofxTimeline*> sublines;
    
private:
    int panelWidth;
    int eventIncrement;
};

class setupScreen {
    
public:
    
    
private:
};