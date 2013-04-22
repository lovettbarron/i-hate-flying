//
//  audioControl.cpp
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-21.
//
//

#include "audioControl.h"

AudioControl::AudioControl() {
    engine.loadSound("sound/engine.wav");
    engine.setLoop(true);
    
    announce.loadSound("sound/announce.wav");
    announce.setLoop(false);
    
    for(int i=0;i<PILOTPHRASE;i++) {
        pilot[i].loadSound("sound/pilot" + ofToString(i) + ".wav");
        pilot[i].setLoop(false);
    }
    baby.loadSound("sound/baby.wav");
    baby.setLoop(false);
    
    landingGear.loadSound("sound/landinggear.wav");
    landingGear.setLoop(false);
    
    ihateflying.loadSound("sound/ihateflying.wav");
    ihateflying.setLoop(false);
    
    coughing.loadSound("sound/coughing.wav");
    coughing.setLoop(false);
    
    bumping.loadSound("sound/bunmping.wav");
    bumping.setLoop(false);
}

AudioControl::~AudioControl() {
    
}

void AudioControl::update() {
    
}

void AudioControl::trigger(AudioType type) {
    switch(type) {
            
        case ENGINE:
            if(!engine.getIsPlaying())
                engine.play();
            break;
            
        case ANNOUNCE:
            if(!announce.getIsPlaying())
                announce.play();
            break;
            
        case BABY:
            if(!baby.getIsPlaying())
                baby.play();
            break;
            
        case LANDINGGEAR:
            if(!landingGear.getIsPlaying())
                landingGear.play();
            break;
            
        case IHATEFLYING:
            if(!ihateflying.getIsPlaying())
                ihateflying.play();
            break;
        case COUGHING:
            if(!coughing.getIsPlaying())
                coughing.play();
            break;
        case BUMPING:
            if(!bumping.getIsPlaying())
                bumping.play();
            break;
        case PILOT:
            {
                bool isSayingSomething = false;
                for(int i=0;i<PILOTPHRASE;i++) {
                    if(pilot[i].getIsPlaying()) isSayingSomething=true;
                }
                if(!isSayingSomething) pilot[int(ofRandom(PILOTPHRASE))].play();
                break;
            }
        default:
            break;
    }
}