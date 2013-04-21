//
//  cabin.h
//  ihateflying
//
//  Created by Andrew Lovett Barron on 2013-04-13.
//
//

#ifndef __ihateflying__cabin__
#define __ihateflying__cabin__


#endif /* defined(__ihateflying__cabin__) */

#include "ofMain.h"
#include "ofx3DModelLoader.h"

struct pingPongBuffer {
public:
    void allocate( int _width, int _height, int _internalformat = GL_RGBA, float _dissipation = 1.0f){
        // Allocate
        for(int i = 0; i < 2; i++){
            FBOs[i].allocate(_width,_height, _internalformat );
        }
        
        // Clean
        clear();
        
        // Set everything to 0
        flag = 0;
        swap();
        flag = 0;
    }
    
    void swap(){
        src = &(FBOs[(flag)%2]);
        dst = &(FBOs[++(flag)%2]);
    }
    
    void clear(){
        for(int i = 0; i < 2; i++){
            FBOs[i].begin();
            ofClear(0,255);
            FBOs[i].end();
        }
    }
    
    ofFbo& operator[]( int n ){ return FBOs[n];}
    
    ofFbo   *src;       // Source       ->  Ping
    ofFbo   *dst;       // Destination  ->  Pong
private:
    ofFbo   FBOs[2];    // Real addresses of ping/pong FBO«s
    int     flag;       // Integer for making a quick swap
};








class Cabin {
    
public:
    Cabin();
    ~Cabin();
    void draw();
    void update();
    void cloudUpdate();
    void setSeatbelt(bool state);
    
    ofFbo windows;
    vector<ofVec3f*> clouds;
private:
    ofVec3f loc;
    ofVec3f rot;
    ofx3DModelLoader * model;
    ofShader toon;
    
    pingPongBuffer posPingPong;
    pingPongBuffer velPingPong;
    
    ofImage windowMask;
    ofImage wingMask;
    
    ofImage cloudImg;
    int maxCloudScale = 100;
    
    ofImage seatbeltOn;
    ofImage seatbeltOff;
    ofImage * seatbelt;
    
    int NUMCLOUDS = 100;
    float cloudSpeed = 1.4;
    
    int ROWS = 20;
    int SEATS = 6;
    int rowDist = 4;
    float seatSep = 1.1;
};

/*

 ofx3DModelLoader();
 ~ofx3DModelLoader();
 
 void loadModel(string modelName, float scale = 1.0);
 void setPosition(float x, float y, float z);
 void setScale(float x, float y, float z);
 void setRotation(int which, float angle, float rot_x, float rot_y, float r_z);
 void draw();
 
 vector <float> rotAngle;
 vector <ofPoint> rotAxis;
 ofPoint scale;
 ofPoint pos;
 
 int numRotations;
 ofx3DBaseLoader * model;

*/