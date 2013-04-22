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
    BABY,
    LANDINGGEAR,
    IHATEFLYING,
    COUGHING,
    BUMPING
};

class AudioControl {
public:
    AudioControl();
    ~AudioControl();
    
    void update();
    void trigger(AudioType type);
    
    
    
private:
    ofSoundPlayer engine;
    ofSoundPlayer announce;
    ofSoundPlayer pilot[PILOTPHRASE];
    ofSoundPlayer baby;
    ofSoundPlayer landingGear;
    ofSoundPlayer ihateflying;
    ofSoundPlayer coughing;
    ofSoundPlayer bumping;
    
    
};

#endif /* defined(__ihateflying__audioControl__) */
