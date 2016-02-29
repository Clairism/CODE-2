//
//  Trees.hpp
//  Recursive Tree
//
//  Created by Claire Hu on 2/29/16.
//
//

#ifndef Trees_hpp
#define Trees_hpp

#include <stdio.h>
#include "ofApp.h"

#endif /* Trees_hpp */

class Tree{

public:

    //properties
    float dotSize;
    float offSetAngleA;
    float offSetAngleB;
    
    //constructor
    Tree();
    
    //methods
    void seed1(float dotSize, float angle, float x, float y);
    void seed2(float dotSize, float angle, float x, float y);
    
};