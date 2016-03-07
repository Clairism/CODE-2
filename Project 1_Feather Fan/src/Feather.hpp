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
    
    float offSetAngleA;
    float offSetAngleB;
    
    int r,g,b;
    
    //Constructor
    Feather();
    
    //Methods
    void growBarb(float size, float angle, float x, float y);    
    void growQuill(float size, float length, float angle, float x, float y);
    
};