//
//  splashScreen.cpp
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-18.
//
//

#include "splashScreen.h"

SplashScreen::SplashScreen() {
    
}

SplashScreen::~SplashScreen() {
    
}

void SplashScreen::draw() {
    ofPushStyle();
	glDepthFunc(GL_ALWAYS); // draw on top of everything

    
    ofPopStyle();
}