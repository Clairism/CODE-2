//
//  KochLines.cpp
//  Exercise 8_2
//
//  Created by Claire Hu on 3/28/16.
//
//

#include "KochLines.hpp"

ofVec2f start;
ofVec2f ending;

KochLine::KochLine(ofVec2f a, ofVec2f b){
    start.set(a.x, a.y);
    end.set(b.x, b.y);
};


void KochLine::display(){
    ofSetColor(0);
    ofNoFill();
    
    ofDrawLine(start.x, start.y, ending.x, ending.y);
}

ofVec2f kochA(){
    return start;
}

ofVec2f kochE(){
    return ending;
}

ofVec2f kochB(){
    ofVec2f v;
    v = (ending,start);
    v /= 3;
    v += start;
    return v;
}

ofVec2f kochD(){
    ofVec2f v;
    v = (ending,start);
    v *= (2/3);
    v += start;
    return v;
}

ofVec2f kochC() {
    ofVec2f a = start;
    
    ofVec2f v = (ending, start);
    v /= 3;
    a += v;
    
    ofRotate(ofRadToDeg(-60));
    a += v;
    
    return a;
}