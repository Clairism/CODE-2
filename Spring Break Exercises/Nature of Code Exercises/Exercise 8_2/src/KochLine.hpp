//
//  KochLine.hpp
//  Exercise 8_2
//
//  Created by Claire Hu on 3/25/16.
//
//

#ifndef KochLine_hpp
#define KochLine_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* KochLine_hpp */


class KochLine{
public:
    
    KochLine(ofVec2f a, ofVec2f b);
    
    ofVec2f start;
    ofVec2f end;
    
    void setup(ofVec2f a, ofVec2f b);
    void draw();
    
    ofVec2f kochA();
    ofVec2f kochB();
    ofVec2f kochC();
    ofVec2f kochD();
    ofVec2f kochE();
    
   /*
    ofPoint kochA();
    ofPoint kochB();
    ofPoint kochC();
    ofPoint kochD();
    ofPoint kochE();
    */
};
