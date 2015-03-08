//
//  ofxDeinterlace.h
//  example
//
//  Created by Atsushi Tadokoro on 3/8/15.
//
//

#pragma once
#define STRINGIFY(A) #A
#include "ofMain.h"

class ofxDeinterlace {
public:
    ofxDeinterlace(ofTexture texture);
    void draw();
    
    string frag;
    string vert;
    ofShader deinterlaceShader;
    ofTexture tex0;
    
    int width;
    int height;
};