//
//  event.h
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#ifndef __ihateflying__event__
#define __ihateflying__event__

#include "ofMain.h"
#include "ofEvents.h"
#include "audioControl.h"

class GameEvent: public ofEventArgs  {
    
public:
    GameEvent() {
        type: NULL;
        amplitude: NULL;
    };
    
    AudioType type;
    float amplitude;
    static ofEvent <GameEvent> events;
    
private:
};
#endif /* defined(__ihateflying__event__) */
