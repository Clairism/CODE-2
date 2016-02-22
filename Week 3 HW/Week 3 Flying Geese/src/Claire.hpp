//
//  Claire.hpp
//  Week 3 Flying Geese
//
//  Created by Claire Hu on 2/21/16.
//
//

#ifndef Claire_hpp
#define Claire_hpp

#include <stdio.h>

#endif /* Claire_hpp */

#include "ofMain.h"

class Goose{
public:
        
    ofImage one;
    ofImage two;
    ofImage three;

    //methods
    void openWings();
    void closeWings();

    //functions
    void draw(float xPos, float yPos);
    
};