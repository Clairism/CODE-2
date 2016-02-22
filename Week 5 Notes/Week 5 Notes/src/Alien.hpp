//
//  Alien.hpp
//  Week 5 Notes
//
//  Created by Claire Hu on 2/22/16.
//
//

#ifndef Alien_hpp
#define Alien_hpp

#include <stdio.h>

#endif /* Alien_hpp */

#include "ofMain.h"

class Alien{
public:
    
    //variables
    int xPos, yPos;
    int r, g, b, alpha;
    int diam;
    int velX, velY;
    
    
    //constructor
    Alien();
    
    
    //methods
    
    void setup(float _mouseX, float _mouseY);
    void update();
    void draw();


};
