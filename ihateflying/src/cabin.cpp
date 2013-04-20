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
    
}

void Cabin::draw() {
    //model->draw();
    
    
    for(int i=0;i<ROWS;i++) {
        ofPushMatrix();
        ofTranslate(i*rowDist,0,0);
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
}