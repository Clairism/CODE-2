//
//  Branch.hpp
//  Tree
//
//  Created by Claire Hu on 3/7/16.
//
//

#ifndef Branch_hpp
#define Branch_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Branch_hpp */

class Branch : public ofBaseApp{ //link this class to ofBaseApp
    
    //properties
    
    //constructor
    
    //methods
    
public:
    void setup(float _xPos, float _yPos,
               float _length, float _width,
               float _splitPercentage,
               float _maxSplitAngle,
               float _maxSubdivitions,
               float _maxSegments,
               float _segmentsSinceStart,
               float _angle,
               float _curvature,
               ofColor _color
               );
    
private:
    float xPos, yPos; // position
    float length, width; //length and width of branches
    float splitPercentage; //perc my branch will actually split
    float maxSplitAngle;
    float maxSubdivions; //max number of divisions
    float maxSegments; //max number of branches
    float segmentsSinceStart; //counte
    float angle, curvature;// give curvature to branches
    ofColor color;//color of the branch
    bool split; //flip stat1 & stat2
    
};