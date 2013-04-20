//
//  pulseEvent.h
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-20.
//
//

#ifndef __ihateflying__pulseEvent__
#define __ihateflying__pulseEvent__

#include "ofMain.h"
#include "ofEvents.h"

class PulseEvent : public ofEventArgs {
    
public:
    PulseEvent() {
        type = NULL;
        payload = NULL;
        //        msg = '';
    }
    
    int type; // 0 sensor, 1 bpm, 2 ibi
    int pin;
    int payload;
    string msg;
    static ofEvent <PulseEvent> events;
};
#endif /* defined(__ihateflying__pulseEvent__) */
