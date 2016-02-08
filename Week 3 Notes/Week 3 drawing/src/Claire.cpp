//
//  Claire.cpp
//  Week 3 drawing
//
//  Created by Claire Hu on 2/8/16.
//
//

#include "Claire.hpp"
#include "ofMain.h"

/*
 Claire::Claire(){
    //initial velues
    height = 10;
    smell = "good";
    string name;
}
 */

void Claire:: walk(){
    //print to the console
    cout << "I'm walking" << endl;
    
}

void Claire:: sleep(){
    cout << "I'm sleeping" << endl;

}

void Claire:: talk(){
    cout << "I'm talking" << endl;


}

void Claire:: eat(){
    cout << "I'm eating" << endl;

}

void Claire:: draw(float xPos, float yPos){
    
    cout << "I'm drawing" << endl;
    
    ofSetColor(r, g, b);
    ofFill();
    ofDrawEllipse(xPos, yPos, height, height);
    
}