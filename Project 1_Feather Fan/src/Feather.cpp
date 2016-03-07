//
//  Feather.cpp
//  Project 1_Feather Fan
//
//  Created by Claire Hu on 3/7/16.
//
//

#include "Feather.hpp"

Feather::Feather(){
    
}

void Feather::growQuill(float size, float length, float quillLength, float angle, float x, float y, ofColor color){
    
    color = quillColor;
    ofSetColor(color);
    ofFill();
    
    //check if length <= quillLength (maxLength);
    
    //draw
    
    //size --, length ++, change angle;

    //call growBarb
    
    //call itself

}

void Feather::growBarb(float size, float angle, float x, float y, ofColor color){
    
    color = barbColor;
    ofSetColor(color);
    ofFill();
    
    //draw (on both sides of the quill) += & -= offSetAngle
    
    //size --;
    
}