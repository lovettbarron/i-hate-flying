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
		void update();
		void draw();
    
        void eventControl(GameEvent &e);

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    // Model
    Cabin * cabin;
    PulseControl * pulse;
    AudioControl * audio;
    ofLight light;
    ofxGameCamera cam;
    ofxAutoControlPanel panel;
    ofxTimeline timeline;
    
private:
    int panelWidth;
};

class setupScreen {
    
public:
    
    
private:
};