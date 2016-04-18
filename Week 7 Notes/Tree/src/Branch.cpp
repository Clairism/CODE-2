//
//  Branch.cpp
//  Tree
//
//  Created by Claire Hu on 3/7/16.
//
//

#include "Branch.hpp"

void Branch::setup(float _xPos, float _yPos,
           float _length, float _width,
           float _splitPercentage,
           float _maxSplitAngle,
           float _maxSubdivions,
           float _maxSegments,
           float _segmentsSinceStart,
           float _angle,
           float _curvature,
           ofColor _color
                   ){
    
//    1.set incoming values to the previous branch values
    
    xPos = _xPos;
    yPos = _yPos;
    length = _length;
    width = _width;
    splitPercentage = _splitPercentage;
    maxSplitAngle = _maxSplitAngle;
    maxSubdivions = _maxSubdivions;
    maxSegments = _maxSegments;
    segmentsSinceStart = _segmentsSinceStart;
    angle = _angle;
    curvature = _curvature;
    color = _color;
    
//    2.check if it splits
    
    float r = ofRandomuf(); //random # btw 0,1;
    if(r > splitPercentage &&
       segmentsSinceStart != maxSegments){ //if so, allow to flip state
        
        split = true;
        
    } else {
        
        split = false;
        
    }
    
//    3.draw the branches
    
    ofSetColor(color);
    ofSetLineWidth(width);
    ofDrawLine(xPos, yPos,
               xPos + length*cos(angle),
               yPos + length*sin(angle)
               );
    
//    4.update the variables
    
    xPos += length*cos(angle);
    yPos += length*sin(angle);
    width = width*ofRandom(0.3, 0.8);
    length = length*ofRandom(0.7, 0.9);
    angle += curvature;
    curvature += ofRandom(0, 2*PI/360);
    
    segmentsSinceStart ++;

    
//    5.recursion
    
    if(segmentsSinceStart <= maxSegments){
        
        if(!split){//checks if it's false
            //create one branch
            
            //call itself
            Branch subBranch;
            //setup
            subBranch.setup(xPos, yPos, length, width,
                            splitPercentage,
                            maxSplitAngle,
                            maxSubdivions,
                            maxSegments,
                            segmentsSinceStart,
                            angle, curvature,
                            color);
            
        } else {
            //create two branch
            
            Branch subBranch1;
            Branch subBranch2;

            float angle1 = angle + ofRandom(0, maxSplitAngle);
            float angle2 = angle - ofRandom(0, maxSplitAngle);
            
            subBranch1.setup(xPos, yPos, length, width,
                            splitPercentage,
                            maxSplitAngle,
                            maxSubdivions,
                            maxSegments,
                            segmentsSinceStart,
                            angle1,
                            curvature,
                            color);
            
            subBranch2.setup(xPos, yPos, length, width,
                             splitPercentage,
                             maxSplitAngle,
                             maxSubdivions,
                             maxSegments,
                             segmentsSinceStart,
                             angle2,
                             curvature,
                             color);
            
        }
    }
    
}
