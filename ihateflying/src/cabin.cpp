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
}

Cabin::~Cabin() {
    toon.load("shader/toon.vert", "shader/toon.frag");
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
    ofSetColor(245);
    ofScale(5,5,5);
    for(int i=0;i<ROWS;i++) {
        ofPushMatrix();
        ofTranslate(i*rowDist,0,0);

        // Making the windows
        ofPushMatrix();
        ofTranslate(0,-20,0);
        
        
        
        ofPopMatrix();
        
        // Making the seats
        for(int j=0;j<SEATS;j++) {
            ofPushMatrix();
            if(j%2) ofTranslate(0,5,0);
            ofTranslate(0,j*seatSep,0);
            ofScale(.5,1,1);
            ofBox(1);
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    toon.end();
}

void Cabin::update() {
    
    
}

void Cabin::cloudUpdate() {
    
}