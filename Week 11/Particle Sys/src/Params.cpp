//
//  Params.cpp
//  Particle Sys
//
//  Created by Claire Hu on 4/11/16.
//
//

#include "Params.hpp"

void Params::setup(float _rad, float _velRad,
                   float _lifeTime, float _time,
                   float _rotate,
                   float _force,
                   float _spin,
                   float _friction){
    eCenter = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    /*
    eRad = 50;
    velRad = 100;
    lifeTime = 1.0;
    rotate = 90;
    
    force =1000;
    spin = 1000;
    friction = 0.05;
     */
    
    eRad = _rad;
    velRad = _velRad;
    lifeTime = _lifeTime;
    rotate = _rotate;
    
    force =_force;
    spin = _spin;
    friction = _friction;
}