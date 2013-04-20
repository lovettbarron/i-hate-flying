//
//  pulseControl.cpp
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#include "pulseControl.h"


PulseControl:: PulseControl() {
    serial.listDevices();
	serial.setup("/dev/tty.usbmodem411",9600);
    ofAddListener(PulseEvent::events, this, &PulseControl::sensorDelegate);
}

PulseControl::~PulseControl() {
    
}

void PulseControl::update() {
    if(serial.available() > 0) {
        
    }
    
}

int PulseControl::getCurrentBPM() {
    
}

int PulseControl::getAverageBPM() {
    
}

void PulseControl::drawHeartRate(int x, int y) {
    
}


void PulseControl::drawBPM(int x, int y) {
    
}

void PulseControl::drawIBI(int x, int y) {
    
}

void PulseControl::sensorDelegate(PulseEvent &e) {
    ofLog() << "type: " << ofToString(e.type) << " payload: " << ofToString(e.payload);

    }
//    String inData = port.readStringUntil('\n');
//    inData = trim(inData);                 // cut off white space (carriage return)
//    
//    if (inData.charAt(0) == 'S'){          // leading 'S' for sensor data
//        inData = inData.substring(1);        // cut off the leading 'S'
//        Sensor = int(inData);                // convert the string to usable int
//    }
//    if (inData.charAt(0) == 'B'){          // leading 'B' for BPM data
//        inData = inData.substring(1);        // cut off the leading 'B'
//        BPM = int(inData);                   // convert the string to usable int
//        beat = true;                         // set beat flag to advance heart rate graph
//        heart = 20;                          // begin heart image 'swell' timer
//    }
//    if (inData.charAt(0) == 'Q'){            // leading 'Q' means IBI data
//        inData = inData.substring(1);        // cut off the leading 'Q'
//        IBI = int(inData);                   // convert the string to usable int
//    }
//}

