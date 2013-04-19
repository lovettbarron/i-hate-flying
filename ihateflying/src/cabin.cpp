//
//  cabin.cpp
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#include "cabin.h"

Cabin::Cabin() {
    // http://sketchup.google.com/3dwarehouse/details?mid=30e8973a2c1b03d6dcef01d31e275203
    // or
    // http://sketchup.google.com/3dwarehouse/details?mid=7b765f7f83e74a93d4713685ae50fa13&prevstart=0
    loadModel("res/model/cabin.dae");
}

Cabin::~Cabin() {
    
}
