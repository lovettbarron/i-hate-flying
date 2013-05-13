//
//  audioControl.h
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-21.
//
//

#ifndef __ihateflying__audioControl__
#define __ihateflying__audioControl__

#include "ofMain.h"
#define PILOTPHRASE 5

enum AudioType {
    ENGINE,
    ANNOUNCE,
    PILOT,
    PILOT_LANDING,
    CREW,
    BABY,
    LANDINGGEAR,
    IHATEFLYING,
    COUGHING,
    TRAY,
    BUMPING,
    COMMENT,
    SMELL
};

class AudioControl {
public:
    AudioControl();
    ~AudioControl();
    
    void update();
    void trigger(AudioType type);
    void resetAll();
    
    
    
private:
    bool bLandingGear, bPilotLanding,bIhateflying; // Once
    
    ofSoundPlayer engine;
    ofSoundPlayer announce;
    ofSoundPlayer pilotLanding;
    ofSoundPlayer pilot[PILOTPHRASE];
    ofSoundPlayer baby;
    ofSoundPlayer landingGear;
    ofSoundPlayer ihateflying;
    ofSoundPlayer coughing;
    ofSoundPlayer bumping;
    ofSoundPlayer smell;
    
    
};

#endif /* defined(__ihateflying__audioControl__) */
