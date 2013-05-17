//
//  splashScreen.h
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-18.
//
//

#ifndef __ihateflying__splashScreen__
#define __ihateflying__splashScreen__

#include "ofMain.h"
#include "ofxTimeline.h"

class SplashScreen {
public:
    SplashScreen();
    ~SplashScreen();
    
    void draw();
    void next();
    void startGame();
    void endGame();
    
    ofImage laGameSpace;
    ofImage relayStudio;
    ofImage ihateflying;
    
    ofImage * current;
    
    int incr;
    bool started, finished;
    
};
#endif /* defined(__ihateflying__splashScreen__) */
