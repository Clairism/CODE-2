//
//  Rectangle.hpp
//  Animation
//
//  Created by Claire Hu on 3/28/16.
//
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Rectangle_hpp */


class Rectangle{
public:
    
    //variables or properties
    float pct;
    ofPoint posA;
    ofPoint posB;
    ofPoint pos;  //output point of Point A & B
    float catchUpSpeed;

    
    //constructor
    Rectangle();
    
    
    //methods
    void interpolate(float myPct);
    void zeno(float catchX, float catchY);
    void draw();
    
    
};