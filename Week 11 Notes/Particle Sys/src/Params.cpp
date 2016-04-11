//
//  Params.cpp
//  Particle Sys
//
//  Created by Claire Hu on 4/11/16.
//
//

#include "Params.hpp"

void Params::setup(){
    eCenter = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    eRad = 50;
    velRad = 100;
    lifeTime = 1.0;
    rotate = 90;
    
    force = 200;
    spin = 1000;
    friction = 0.05;
}