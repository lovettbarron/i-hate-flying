//
//  pulseControl.h
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#ifndef __ihateflying__pulseControl__
#define __ihateflying__pulseControl__

#include "ofMain.h"
#include "ofEvents.h"
#include "ofSerial.h"

class PulseControl : public ofSerial {
    
public:
    PulseControl();
    ~PulseControl();
    
    int getCurrentBPM();
    int getAverageBPM();

    void drawHeartRate(int x, int y);
    void drawBPM(int x, int y);

private:
    vector<int> heartrate;
    int current;
    
    ofSerial Serial;
    

    
};


#endif /* defined(__ihateflying__pulseControl__) */
