//
//  pulseControl.h
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#ifndef __ihateflying__pulseControl__
#define __ihateflying__pulseControl__

#include "ofMain.h"
#include "ofEvents.h"
#include "ofSerial.h"
#include "pulseEvent.h"
#include "ofxCv.h"

class PulseControl {
    
public:
    PulseControl();
    ~PulseControl();
    
    void update();
    void calcFrame();
    
    int getCurrentBPM();
    int getAverageBPM();
    
    int getCurrentIBI();
    int getAverageIBI();

    void drawHeartRate(int x, int y);
    void drawBPM(int x, int y);
    void drawIBI(int x, int y);
    
    void drawDebug();
    
    void sensorDelegate(PulseEvent &e);
    
private:
    vector<int> heartrate;
    vector<int> bpm;
    vector<int> ibi;
    int currentBPM;
    int currentIBI;
    const bool bCam=true;
    
    ofSerial serial;
    string buffer;
    bool stringComplete = false;
    
    //Camera
    
    ofVideoGrabber cam;
	ofImage gray, graySmall;
    float scaleFactor;
	cv::CascadeClassifier classifier;
	vector<cv::Rect> objects;
};


#endif /* defined(__ihateflying__pulseControl__) */
