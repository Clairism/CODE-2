//
//  Feather.cpp
//  Project 1_Feather Fan
//
//  Created by Claire Hu on 3/7/16.
//
//

#include "Feather.hpp"


/*LOGIC:
 
void Feather::growQuill(float size,float angle, float x, float y){
    
    //if (length <= maxQuillLength)
        
    //draw
    
    //size --, length ++;

    //call growBarb

    //call itself

}

void Feather::growBarb(float size, float angle, float x, float y){
    
    //draw (on both sides of the quill) += & -= offSetAngle
    
    //size --;

}
 */

Feather::Feather(){
    
}

void Feather::growQuill(float size, float angle, float x, float y){
    
    if(size > 1.0){
    
            ofSetColor(quillColor);
            ofFill();
            //ofDrawCircle(x, y, size);
            
            float newX = x + cos(angle)*size;
            float newY = y + sin(angle)*size;
        
            ofDrawLine(x, y, newX, newY);
            
            growQuill(size*0.98, angle, newX, newY);
        
            growBarb(size*0.8, angle + PI/3, newX, newY);
            growBarb(size*0.8, -angle + PI/3, newX, newY);

    }
}

void Feather::growBarb(float size, float angle, float x, float y){
    
    if(size > 1.0){
        
            ofSetColor(barbColor);
            ofFill();
            //ofDrawCircle(x, y, size);
            
            float newX = x + cos(angle)*size;
            float newY = y + sin(angle)*size;
        
            ofDrawLine(x, y, newX, newY);
        
            growBarb(size*0.8, angle + PI/3, newX, newY);
            growBarb(size*0.6, -angle + PI/3, newX, newY);
    }
}