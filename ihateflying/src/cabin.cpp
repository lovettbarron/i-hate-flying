//
//  cabin.cpp
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#include "cabin.h"

Cabin::Cabin() {
    // http://sketchup.google.com/3dwarehouse/details?mid=30e8973a2c1b03d6dcef01d31e275203
    // or
    // http://sketchup.google.com/3dwarehouse/details?mid=7b765f7f83e74a93d4713685ae50fa13&prevstart=0

 //   model = new ofx3DModelLoader();
   // model->loadModel("res/model/cabin/cabin.3ds");
    toon.load("shader/toon.vert", "shader/toon.frag");
    
    seatbeltOn.loadImage("image/seatbelt_on.png");
    seatbeltOff.loadImage("image/seatbelt_off.png");
    seatbelt = &seatbeltOn;
    
    windows.allocate(500,500);
    windowMask.loadImage("image/windowmask.png");
    cloudImg.loadImage("image/cloud.png");
    for(int i=0;i<NUMCLOUDS;i++) {
        clouds.push_back( new ofVec3f(
                                  ofRandom(windows.getWidth()),
                                  ofRandom(windows.getHeight()),
                                  ofRandom(maxCloudScale)
                                  )
                          );
    }
    cloudUpdate();
}

Cabin::~Cabin() {
}

void Cabin::draw() {
    
    //model->draw();
    toon.begin();
    
    toon.setUniform3f("uBaseColor", 1.0f, 0.0f, 0.0f );
    toon.setUniform3f("uDirLightPos", 0, 0, 0 );
    toon.setUniform3f("uDirLightColor", 20, 0, 0 );
    toon.setUniform3f("uAmbientLightColor", .7, .7, .7 );
//    toon.setAttribute3f("vNormal", 20, 0, 0 );
//    toon.setAttribute3f("vRefract", 20, 0, 0 );
//
//    uniform vec3 uBaseColor;
//    uniform vec3 uDirLightPos;
//    uniform vec3 uDirLightColor;
//    uniform vec3 uAmbientLightColor;
//    varying vec3 vNormal;
//    varying vec3 vRefract;
    ofPushMatrix();
    ofSetColor(200);
    ofScale(5,5,5);
    ofRotateY(90);
    for(int i=0;i<ROWS;i++) {
        ofPushMatrix();
        ofTranslate(i*rowDist,0,0);
        if(windows.isAllocated()) {
            // Making the windows
            // First window
            ofPushMatrix();
            ofTranslate(0,-4,2);
            ofRotateX(90);
            ofRotateY(0);
            ofRotateZ(90);
            windows.draw(0, 0, 2, 2);
            ofPopMatrix();
            
            //Second window
            ofPushMatrix();
            ofTranslate(0, seatSep*4*SEATS + (SEATS * 2 * .6),2);
            ofRotateX(90);
            ofRotateY(0);
            ofRotateZ(-90);
            windows.draw(0, 0, 2, 2);
            ofPopMatrix();
            
        }
        // Making the seats
        for(int j=0;j<SEATS;j++) {
            ofPushMatrix();
            
            
            ofScale(2,4,2);
            if(j%2) ofTranslate(0,2,0);
            ofTranslate(0, j*seatSep,0);
            
            // This defines the seatbelt above the seat
            ofPushMatrix();
            ofTranslate(0,0,3);
            ofRotateX(90);
            ofRotateY(45);
            ofSetColor(255);
            seatbelt->draw(0,0,1,seatbelt->getHeight() / seatbelt->getWidth() );
            ofSetColor(200);
            ofPopMatrix();
            
            ofBox(1);
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    toon.end();
}

void Cabin::update() {
    cloudUpdate();
}

void Cabin::setSeatbelt(bool state) {
    if(state)
        seatbelt = &seatbeltOn;
    else
        seatbelt = &seatbeltOff;
}

void Cabin::cloudUpdate() {
    windows.begin();
    ofBackground(200);
    ofSetColor(255);
    for(int i=0;i<clouds.size();i++) {
        clouds[i]->set(clouds[i]->x+cloudSpeed, clouds[i]->y);
        if(clouds[i]->x > windows.getWidth() + 5)
            clouds[i]->set(ofVec3f(0,ofRandom(windows.getHeight())));
        cloudImg.draw(clouds[i]->x, clouds[i]->y,clouds[i]->z,clouds[i]->z);
    }
    windowMask.draw(0,0,windows.getWidth(),windows.getHeight());
    windows.end();
}