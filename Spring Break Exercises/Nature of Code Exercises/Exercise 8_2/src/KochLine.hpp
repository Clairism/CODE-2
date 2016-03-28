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
    
    ofVec2f kochA(){
        return start;
    }
    
    ofVec2f kochB(){
        ofVec2f v;
        v.x = end.x - start.x;
        v.y = end.y - start.y;
        
        v /= 3;
        v += start;
        return v;
    }
    
    ofVec2f kochC() {
        ofVec2f a = start;
        
        ofVec2f v;
        v.x = end.x - start.x;
        v.y = end.y - start.y;
        v /= 3;
        a += v;
        
        ofRotate(-ofRadToDeg(60));
        a += v;
        
        return a;
    }
    
    ofVec2f kochD(){
        ofVec2f v;
        v.x = end.x - start.x;
        v.y = end.y - start.y;
        v *= (2/3);
        v += start;
        return v;
    }
    
    ofVec2f kochE(){
        return end;
    }
    
    
    void draw();

    
   /*
    ofPoint kochA();
    ofPoint kochB();
    ofPoint kochC();
    ofPoint kochD();
    ofPoint kochE();
    */
};
