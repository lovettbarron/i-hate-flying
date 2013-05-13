//
//  cabin.cpp
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#include "cabin.h"

Cabin::Cabin(AudioControl &_audio) {
    
    audio = &_audio;
    
    toon.load("shader/toon.vert", "shader/toon.frag");
    
    seatbeltOn.loadImage("image/seatbelt_on.png");
    seatbeltOff.loadImage("image/seatbelt_off.png");
    seatbelt = &seatbeltOn;
    
    windows.allocate(500,500,GL_RGBA);
    windowMask.loadImage("image/windowmask.png");
    cloudImg.loadImage("image/cloud.png");
    for(int i=0;i<NUMCLOUDS;i++) {
        clouds.push_back( new ofVec3f(
                                  ofRandom(windows.getWidth()),
                                  ofRandom(windows.getHeight()),
                                  ofRandom(maxCloudScale)
                                  )
                          );
    }
    cloudUpdate();
    seatbelt = &seatbeltOff;
    audio->trigger(ENGINE);
    
}

Cabin::~Cabin() {
}

void Cabin::setupSound() {
    
}

void Cabin::draw() {
    
    //model->draw();
    toon.begin();
    
    toon.setUniform3f("uBaseColor", 1.0f, 0.0f, 0.0f );
    toon.setUniform3f("uDirLightPos", 0, 0, 0 );
    toon.setUniform3f("uDirLightColor", 20, 0, 0 );
    toon.setUniform3f("uAmbientLightColor", .7, .7, .7 );
//    toon.setAttribute3f("vNormal", 20, 0, 0 );
//    toon.setAttribute3f("vRefract", 20, 0, 0 );
//
//    uniform vec3 uBaseColor;
//    uniform vec3 uDirLightPos;
//    uniform vec3 uDirLightColor;
//    uniform vec3 uAmbientLightColor;
//    varying vec3 vNormal;
//    varying vec3 vRefract;
    ofPushMatrix();
    ofEnableAlphaBlending();
    ofSetColor(255);
    ofScale(5,5,5);
    ofRotateY(90);
    for(int i=0;i<ROWS;i++) {
        ofPushMatrix();
        ofTranslate(i*rowDist,0,0);
        if(windows.isAllocated()) {
            // Making the windows
            // First window
            ofPushMatrix();
            ofTranslate(0,-4,2);
            ofRotateX(90);
            ofRotateY(-180);
            ofRotateZ(0);
            windows.draw(0, 0, 2, 2);
            ofPopMatrix();
            
            //Second window
            ofPushMatrix();
            ofTranslate(0, seatSep*4*SEATS + (SEATS * 2 * .6),2);
            ofRotateX(90);
            ofRotateY(0);
            ofRotateZ(0);
            windows.draw(0, 0, 2, 2);
            ofPopMatrix();
            
        }
        ofSetColor(200);
        // Making the seats
        for(int j=0;j<SEATS;j++) {
            ofPushMatrix();
            
            
            ofScale(2,4,2);
            if(j%2) ofTranslate(0,2,0);
            ofTranslate(0, j*seatSep,0);
            
            // This defines the seatbelt above the seat
            ofPushMatrix();
            ofTranslate(0,0,3);
            ofRotateX(90);
            ofRotateY(45);
            ofSetColor(255);
            seatbelt->draw(0,0,1,seatbelt->getHeight() / seatbelt->getWidth() );
            ofSetColor(200);
            ofPopMatrix();
            
            ofBox(1);
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    toon.end();
}

void Cabin::update() {
    cloudUpdate();
}

void Cabin::setSeatbelt(bool state) {
    if(state)
        seatbelt = &seatbeltOn;
    else
        seatbelt = &seatbeltOff;
    audio->trigger(ANNOUNCE);
}

void Cabin::cloudUpdate() {
    windows.begin();
    ofBackground(200,200,255);
    ofSetColor(255,50);
    for(int i=0;i<clouds.size();i++) {
        clouds[i]->set(clouds[i]->x+cloudSpeed, clouds[i]->y,clouds[i]->z);
        if(clouds[i]->x > windows.getWidth() + 5)
            clouds[i]->set(0,ofRandom(windows.getHeight()),clouds[i]->z);
       // cloudImg.draw(clouds[i]->x, clouds[i]->y,clouds[i]->z,clouds[i]->z);
        ofCircle(clouds[i]->x, clouds[i]->y,0,clouds[i]->z);
    }
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
    ofSetColor(255,255);
    windowMask.draw(0,0,1,windows.getWidth(),windows.getHeight());
    windows.end();
}

/////
void Cabin::randomEvent() {
    int random = ofRandom(0,8);
    switch(random) {
        case 0:
            turbulence();
            break;
        case 1:
            cabinCrew();
            break;
        case 2:
            garbledAnnouncement();
            break;
        case 3:
            inappropriateComment();
            break;
        case 4:
            landingGear();
            break;
        case 5:
            fallingTraytable();
            break;
        case 6:
            weirdSmell();
            break;
        case 7:
            babyCrying();
            break;
    }
}

/////

void Cabin::turbulence() {
    audio->trigger(BUMPING);
}

void Cabin::cabinCrew() {
    audio->trigger(CREW);
}

void Cabin::garbledAnnouncement() {
    audio->trigger(PILOT);
}

void Cabin::inappropriateComment() {
    audio->trigger(COMMENT);
}

void Cabin::landingGear() {
    audio->trigger(LANDINGGEAR);
}

void Cabin::fallingTraytable() {
     audio->trigger(TRAY);
}

void Cabin::weirdSmell() {
    audio->trigger(SMELL);
}

void Cabin::babyCrying() {
    audio->trigger(BABY);
}