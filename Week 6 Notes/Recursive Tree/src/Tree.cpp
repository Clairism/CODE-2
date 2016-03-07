//
//  Tree.cpp
//  Week 6 -- Recursive Tree
//
//  Created by Claire Hu on 3/7/16.
//
//

#include "Tree.hpp"

Tree::Tree(){
    
}

void Tree:: seed1(float dotSize, float angle, float x, float y){
    
    if(dotSize > 1.0){
        
        float r = ofRandomuf(); // returns a random # btwn 0,1
        
        if(r > 0.02 ){// this happens 98% of the time
            
//            SOLVING -- seed 1 is white
            ofSetColor(255);
            ofFill();
            ofDrawCircle(x, y, dotSize);
            
            float newX = x + cos(angle)*dotSize;
            float newY = y + sin(angle)*dotSize;
            
            seed1(dotSize*0.99, angle - offSetAngleA, newX, newY);
            
        } else {
            // this happens 2% of the time
//            SOLVING -- slightly change the direction of the next branch
            ofSetColor(0,0,255);
            ofFill();
            ofDrawCircle(x, y, dotSize);
            
            float newX = x + cos(angle); //cos -- implementation range btw -1,1;
            float newY = y + sin(angle);
            
            seed1(dotSize*0.99, angle + offSetAngleA, newX, newY);
//            SOLVING -- seed 1 left side branches; seed 2 right side branches
            //seed2(dotSize*0.6, angle + offSetAngleB, newX, newY);
            seed1(dotSize*0.5, angle - offSetAngleB, newX, newY);
        }
        
    }
    
}




void Tree:: seed2(float dotSize, float angle, float x, float y){
    
    if(dotSize > 1.0){
        
        float r = ofRandomuf();
        
        if(r > 0.05){
            
//            SOLVING -- seed 2 is red
            ofSetColor(255, 0, 0);
            ofFill();
            ofDrawCircle(x, y, dotSize);
            
            float newX = x + cos(angle)*dotSize;
            float newY = y + sin(angle)*dotSize;
            
            seed2(dotSize*0.99, angle + offSetAngleA, newX, newY);
            
        } else {
            
            ofSetColor(255);
            ofFill();
            ofDrawCircle(x, y, dotSize);
            
            float newX = x + cos(angle);
            float newY = y + sin(angle);
            
            seed2(dotSize*0.99, angle - offSetAngleA, newX, newY);
            seed1(dotSize*0.6, angle + offSetAngleB, newX, newY);
            seed2(dotSize*0.5, angle - offSetAngleB, newX, newY);
            
        }
    }
}

