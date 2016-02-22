//
//  Claire.cpp
//  Week 3 Flying Geese
//
//  Created by Claire Hu on 2/21/16.
//
//

#include "Claire.hpp"
#include "ofMain.h"


void Goose:: openWings(){
    
    one.load("images/1st.png");
    two.load("images/1-1.png");
    three.load("images/2-1.png");
    
}

void Goose:: closeWings(){
    
    one.load("images/1st.png");
    two.load("images/1-2.png");
    three.load("images/2-2.png");
    
}

void Goose:: draw(float xPos, float yPos){

    float y = yPos - 50;
    
    one.draw(xPos, y, 150, 100);
    two.draw(xPos - ofGetWidth()/4, yPos - ofGetHeight()/4, 150, 100);
    three.draw(xPos - ofGetWidth()/4, yPos + ofGetHeight()/5, 150, 100);

    three.draw(xPos - 2*ofGetWidth()/4, y - 2*ofGetHeight()/5, 150, 100);
    two.draw(xPos - 2*ofGetWidth()/4, y + 2*ofGetHeight()/5, 150, 100);


}