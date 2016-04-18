//
//  particle.hpp
//  Particle Sys
//
//  Created by Claire Hu on 4/11/16.
//
//

#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>

#include "Params.hpp"
#include "ofMain.h"


#endif /* particle_hpp */

class Particle{
public:
    
    //constructor
    Particle();
    
    //methods
    void setup();
//    void setup(float rad, float velRad, float _lifeTime);
    void update(float dt);
    void draw();
    
    //variables
    Params param; //instance of parameters in the class
    ofPoint pos; // position of the particle
    ofPoint vel; // speed of the particle
    float time; // how long the particle has been living
    float lifeTime; //max time the particle can live
    bool live; //checks whether particle is alive or dead
    
    ofPoint randomPointIncircle(float maxRad); //random point in a circle
    
    
};