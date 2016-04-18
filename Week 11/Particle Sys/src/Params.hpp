//
//  Params.hpp
//  Particle Sys
//
//  Created by Claire Hu on 4/11/16.
//
//

#ifndef Params_hpp
#define Params_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Params_hpp */

class Params{
public:
    
    void setup(float _rad, float _velRad,
               float _lifeTime, float _time,
               float _rotate,
               float _force,
               float _spin,
               float _friction
               );
    
    ofPoint eCenter; //center of the emitter
    float eRad; //the size of the emitter
    float velRad; //bound on our particle's velocity
    float lifeTime; //max lifetime
    float time; // time since it was born
    float rotate;
    
    float force; // attraction & repulsion
    float spin; //rotating force
    float friction; //frcition force
};