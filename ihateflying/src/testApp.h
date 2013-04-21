#pragma once

#include "ofMain.h"
#include "ofxAutoControlPanel.h"
#include "ofxGameCamera.h"
#include "pulseControl.h"
#include "cabin.h"

#define SETPANEL 1

class testApp : public ofBaseApp{

	public:
		void setup();
        void setupPanel();
		void update();
		void draw();

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
    ofLight light;
    ofxGameCamera cam;
    ofxAutoControlPanel panel;
    
private:
    int panelWidth;
};

class setupScreen {
    
public:
    
    
private:
};