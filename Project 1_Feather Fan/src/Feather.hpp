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
    float quillLength;
    
    float offSetAngle;
    ofColor barbColor;
    ofColor quillColor;
    
    bool grow;
    
    //Constructor
    Feather();
    
    //Methods
    
    void growQuill(float size, float length, float quillLength, float angle, float x, float y, ofColor color);
    void growBarb(float size, float angle, float x, float y, ofColor color);
    
};