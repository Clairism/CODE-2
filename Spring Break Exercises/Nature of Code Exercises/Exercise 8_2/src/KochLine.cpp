//
//  KochLine.cpp
//  Exercise 8_2
//
//  Created by Claire Hu on 3/25/16.
//
//

#include "KochLine.hpp"

KochLine::KochLine(ofVec2f a, ofVec2f b){
    start = a;
    end = b;
}

void KochLine::draw(){
    ofSetColor(0);
    ofFill();
    
    ofDrawLine(start.x, start.y, end.x, end.y);
}




