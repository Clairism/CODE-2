//
//  Tree.hpp
//  Week 6 -- Recursive Tree
//
//  Created by Claire Hu on 3/7/16.
//
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "ofMain.h" //#include "ofApp.h" --> Redefinition of class

#endif /* Tree_hpp */

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