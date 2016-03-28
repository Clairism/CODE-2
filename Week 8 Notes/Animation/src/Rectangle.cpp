//
//  Rectangle.cpp
//  Animation
//
//  Created by Claire Hu on 3/28/16.
//
//

#include "Rectangle.hpp"

Rectangle::Rectangle(){
    
    //pointA(10, 10)
    posA.x = 10;
    posA.y = 10;
    
    //pointB(1000, 10)
    posB.x = 1000;
    posB.y = 10;
    
}


/*void Rectangle::interpolate(float myPct){
    
//    pos.x = (1-myPct)*posA.x + myPct*posB.x;
//    pos.y = (1-myPct)*posA.y + myPct*posB.y;

    
    //powers
    pct = powf(myPct, 2); //mypCT^2 = myPct * myPct
    pos.x = (1-myPct)*posA.x + myPct*posB.x;
    pos.y = (1-myPct)*posA.y + myPct*posB.y;

    //zeno -- constantly 50%
}*/

void Rectangle::interpolate(float myPct){
    //linear interpolate
    //pos.x = (1 - myPct)*posA.x + myPct*posB.x;
    //pos.y = (1 - myPct)*posA.y + myPct*posB.y;
    
    //powers
    pct = powf(myPct, 0.4); //myPct^2 = myPct* myPct
    pos.x = (1 - pct)*posA.x + pct*posB.x;
    pos.y = (1 - pct)*posA.y + pct*posB.y;
    cout << "pos.x: " << pos.x << endl;
    cout << "pos.y: " << pos.y << endl;
}

void Rectangle::zeno(float catchX, float catchY){
    //pos.x = catchUpSpeed * catchX + (1 - catchUpSpeed)*pos.x;
//    pos.y = catchUpSpeed * catchY + (1 - catchUpSpeed)*pos.y;
    cout << "pos.x: " << pos.x << endl;
    cout << "pos.y: " << pos.y << endl;
}



void Rectangle::draw(){
    
    ofDrawRectangle(pos.x, pos.y, 100, 100);
    
}
