//
//  Alien.cpp
//  Week 5 Notes
//
//  Created by Claire Hu on 2/22/16.
//
//

#include "Alien.hpp"

Alien::Alien(){
    diam = 100;
    velX = ofRandom(-4, 3);
    velY = ofRandom(-6, 2);

};

void Alien::setup(float _mouseX, float _mouseY){
    
    xPos = _mouseX;
    yPos = _mouseY;
    
    r = ofRandom(0,255);
    g = ofRandom(0,255);
    b = ofRandom(50,255);
    alpha = ofRandom(0,255);
    
};


void Alien::update(){
    xPos = xPos + velX;
    yPos = yPos + velY;
    
};


void Alien::draw(){
    ofSetColor(r, g, b, alpha);
    ofFill();
    ofDrawCircle(xPos, yPos, diam);
    
};
