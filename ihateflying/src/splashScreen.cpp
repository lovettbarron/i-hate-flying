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
        ofBackground(255);
        glDepthFunc(GL_ALWAYS);
        // Center the image
        ofPushMatrix();
        ofTranslate((ofGetWidth()-current->getWidth())/2,(ofGetHeight()-current->getHeight())/2);
        current->draw(0,0);
        ofPopMatrix();
    }
    else if(finished) {
        ofPushMatrix();
        glDepthFunc(GL_ALWAYS);
        ofVec2f p = ofVec2f(ofGetWidth() * .1, ofGetHeight() *.1);
        ofDrawBitmapString("You've Landed this time.",
                           p);
        ofDrawBitmapString("Your Empathy Score is",
                           p + (0,p.y));
        ofDrawBitmapString("Default",
                           p + (0,p.y*2));
        ofDrawBitmapString("To Play Again, get your heartrate to 80bpm",
                           p + (0,p.y*4));
        
        ofPopMatrix();
    }
}

void SplashScreen::startGame() {
    started = true; finished = false;
}

void SplashScreen::endGame() {
    finished = true; started = false;
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

