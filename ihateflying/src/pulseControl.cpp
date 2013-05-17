//
//  pulseControl.cpp
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#include "pulseControl.h"


using namespace cv;
using namespace ofxCv;

PulseControl:: PulseControl() {
    if(!bCam) {
        serial.listDevices();
        serial.setup("/dev/tty.usbmodem411",9600);
    } else {
        classifier.load(ofToDataPath("haarcascade_frontalface_alt2.xml"));
        
        scaleFactor = .25;
        cam.initGrabber(640, 480);
        
        // shouldn't need to allocate, resize should do this for us
        graySmall.allocate(cam.getWidth() * scaleFactor, cam.getHeight() * scaleFactor, OF_IMAGE_GRAYSCALE);

    
    }
    ofAddListener(PulseEvent::events, this, &PulseControl::sensorDelegate);
}

PulseControl::~PulseControl() {
    
}

void PulseControl::drawDebug() {
    ofPushMatrix();
    ofTranslate(ofGetWidth()-cam.getWidth(), ofGetHeight()-cam.getHeight());
    cam.draw(0, 0);

    ofNoFill();

    ofScale(1 / scaleFactor, 1 / scaleFactor);
    for(int i = 0; i < objects.size(); i++) {
        ofRect(toOf(objects[i]));
    }

    ofDrawBitmapString(ofToString(objects.size()), 10, 20);
}


void PulseControl::update() {
    if(!bCam){
        if(serial.available()) {
            buffer += serial.readByte();
            //ofLog() << buffer;
            
            
            if(buffer.at(buffer.length() - 1) == '\r') {
                ofLog() << buffer;
                //        static PulseEvent event;
                //        if(buffer
                //        event.type    = 2;
                //        event.payload = 0;
                //        ofNotifyEvent(PulseEvent::events, event);
                buffer = "";
            }
        }
    } else {
        cam.update();
        if(cam.isFrameNew()) {
            convertColor(cam, gray, CV_RGB2GRAY);
            resize(gray, graySmall);
            Mat graySmallMat = toCv(graySmall);
            if(ofGetMousePressed()) {
                equalizeHist(graySmallMat, graySmallMat);
            }
            graySmall.update();
            
            classifier.detectMultiScale(graySmallMat, objects, 1.06, 1,
                                        //CascadeClassifier::DO_CANNY_PRUNING |
                                        //CascadeClassifier::FIND_BIGGEST_OBJECT |
                                        //CascadeClassifier::DO_ROUGH_SEARCH |
                                        0);
        }
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

void PulseControl::calcFrame() {
    
}
