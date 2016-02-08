//
//  Claire.hpp
//  Week 3 drawing
//
//  Created by Claire Hu on 2/8/16.
//
//

#ifndef Claire_hpp
#define Claire_hpp

#include <stdio.h>

#endif /* Claire_hpp */

#include "ofMain.h"


class Claire{
public:
    
    //properties
    int height;
    //ofColor fur;
    int r, g, b;
    string smell;
    string name;
    
    //methods
    void walk();
    void sleep();
    void eat();
    void talk();
    
    //functions to show visuals
    void draw(float xPos, float yPos);
    
};