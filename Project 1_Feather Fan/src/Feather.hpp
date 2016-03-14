//
//  Feather.hpp
//  Project 1_Feather Fan
//
//  Created by Claire Hu on 3/7/16.
//
//

#ifndef Feather_hpp
#define Feather_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Feather_hpp */

class Feather{
public:
    
    //Properties
    float barbSize;
    float quillSize;
    float maxQuillLength;
    
    float offSetAngle;
    
    ofColor quillColor = ofColor(0);
    ofColor barbColor = ofColor(25, 200, 255);
    
    bool grow;
    
    //Constructor
    Feather();
    
    //Methods
    
    void growQuill(float size, float angle, float x, float y);
    void growBarb(float size, float angle, float x, float y);
    
};