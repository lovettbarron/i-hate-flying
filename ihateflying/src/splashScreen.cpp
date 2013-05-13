//
//  splashScreen.cpp
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-18.
//
//

#include "splashScreen.h"

SplashScreen::SplashScreen() {
    incr = 0;
    started = false;
    
    laGameSpace.loadImage("image/splash.png");
    relayStudio.loadImage("image/relay.png");
    ihateflying.loadImage("image/cloud.png");
    next();
}

SplashScreen::~SplashScreen() {
    
}

void SplashScreen::draw() {
    if(!started) {
        ofPushStyle();
        glDepthFunc(GL_ALWAYS); // draw on top of everything
        current->draw(0,0,ofGetWidth(),ofGetHeight());
        
        ofPopStyle();
    }
}

void SplashScreen::startGame() {
    started = true;
}

void SplashScreen::next() {
    switch(incr) {
        case 0:
            current = &relayStudio;
            break;
        case 1:
            current = &laGameSpace;
            break;
        case 2:
            current = &ihateflying;
            break;
        default:
            break;
    }
    incr++;
}