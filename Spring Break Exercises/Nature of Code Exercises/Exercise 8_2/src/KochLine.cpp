//
//  KochLine.cpp
//  Exercise 8_2
//
//  Created by Claire Hu on 3/25/16.
//
//

#include "KochLine.hpp"

ofVec2f start;
ofVec2f _end;

KochLine::KochLine(ofVec2f a, ofVec2f b){
    
    start.set(a.x, a.y);
    end.set(b.x, b.y);
};

void KochLine::setup(ofVec2f a, ofVec2f b){
    
    start.set(a.x, a.y);
    end.set(b.x, b.y);

};


void KochLine::draw(){
    ofSetColor(0);
    ofNoFill();
    
    ofDrawLine(start.x, start.y, _end.x, _end.y);
};

ofVec2f kochA(){
    return start;
};

ofVec2f kochE(){
    return _end;
};

ofVec2f kochB(){
    ofVec2f v;
    v = (_end,start);
    v /= 3;
    v += start;
    return v;
};

ofVec2f kochD(){
    ofVec2f v;
    v = (_end,start);
    v *= (2/3);
    v += start;
    return v;
};

ofVec2f kochC() {
    ofVec2f a = start;
    
    ofVec2f v = (_end, start);
    v /= 3;
    a += v;
    
    ofRotate(ofRadToDeg(-60));
    a += v;
    
    return a;
};