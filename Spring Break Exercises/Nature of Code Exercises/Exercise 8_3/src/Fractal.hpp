//
//  Fractal.hpp
//  Exercise 8_3
//
//  Created by Claire Hu on 3/28/16.
//
//

#ifndef Fractal_hpp
#define Fractal_hpp

#include <stdio.h>
#include "KochLine.hpp"
#include "ofMain.h"

#endif /* Fractal_hpp */

/*
class KochFractal {
public:
    ofVec2f start;       // A ofVec2f for the start
    ofVec2f end;         // A ofVec2f for the end
    
    vector <KochLine> Lines;
    
    int count;
    
    KochFractal() {
        start.set(0, ofGetHeight()-20);
        end.set(ofGetWidth(), ofGetHeight()-20);
        
        vector <KochLine> Lines;
        restart();
    }
    
    void nextLevel() {
        // For every line that is in the arraylist
        // create 4 more lines in a new arraylist
        Lines = iterate(lines);
        count++;
    }
    
    void restart() {
        count = 0;      // Reset count
        Lines.clear();  // Empty the array list
        lines.add(new KochLine(start,end));  // Add the initial line (from one end ofVec2f to the other)
    }
    
    int getCount() {
        return count;
    }
    
    // This is easy, just draw all the lines
    void render() {
        for(KochLine l : Lines) {
            l.display();
        }
    }
    
    // This is where the **MAGIC** happens
    // Step 1: Create an empty arraylist
    // Step 2: For every line currently in the arraylist
    //   - calculate 4 line segments based on Koch algorithm
    //   - add all 4 line segments into the new arraylist
    // Step 3: Return the new arraylist and it becomes the list of line segments for the structure
    
    // As we do this over and over again, each line gets broken into 4 lines, which gets broken into 4 lines, and so on. . .
    ArrayList iterate(ArrayList<KochLine> before) {
        ArrayList now = new ArrayList<KochLine>();    // Create emtpy list
        for(KochLine l : before) {
            // Calculate 5 koch ofVec2fs (done for us by the line object)
            ofVec2f a = l.start();
            ofVec2f b = l.kochleft();
            ofVec2f c = l.kochmiddle();
            ofVec2f d = l.kochright();
            ofVec2f e = l.end();
            // Make line segments between all the ofVec2fs and add them
            now.add(new KochLine(a,b));
            now.add(new KochLine(b,c));
            now.add(new KochLine(c,d));
            now.add(new KochLine(d,e));
        }
        return now;
    }
    
}
;*/






