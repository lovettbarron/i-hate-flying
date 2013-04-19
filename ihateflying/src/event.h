//
//  event.h
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#ifndef __ihateflying__event__
#define __ihateflying__event__

#include <iostream>
#include "testApp.h"

#endif /* defined(__ihateflying__event__) */


class Event: public ofEventArgs  {
    
public:
    Event();
    ~Event();
    
    void update();
    void draw();
    
private:
};