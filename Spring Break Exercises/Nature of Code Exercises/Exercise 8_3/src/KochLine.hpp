//
//  KochLine.hpp
//  Exercise 8_3
//
//  Created by Claire Hu on 3/28/16.
//
//

#ifndef KochLine_hpp
#define KochLine_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofMain.h"


#endif /* KochLine_hpp */


class KochLine{
public:
    
    
    KochLine(ofVec2f start, ofVec2f end) {
        a = start;
        b = end;
    }
    
    ofVec2f a;
    ofVec2f b;
    
    ofVec2f start() {
        return a;
    }
    
    ofVec2f end() {
        return b;
    }
    
    ofVec2f kochleft() {
        ofVec2f v;
        v.x = b.x - a.x;
        v.y = b.y - a.y;
        v/=3;
        v += a;
        return v;
    }
    
    ofVec2f kochmiddle() {
        ofVec2f v;
        v.x = b.x - a.x;
        v.y = b.y - a.y;
        v/=3;
        
        ofVec2f p;
        p = a;
        p += v;
        
        v.rotate(-60);
        p += v;
        
        return p;
    }
    
    
    ofVec2f kochright() {
        ofVec2f v;
        v.x = a.x - b.x;
        v.y = a.y - b.y;
        v/=3;
        v+=b;
        return v;
    }
 
    
    void draw();

};






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
        Lines = iterate(Lines);
        count++;
    }
    
    void restart() {
        count = 0;      // Reset count
        Lines.clear();  // Empty the array list
        Lines.push_back(KochLine(start,end));  // Add the initial line (from one end ofVec2f to the other)
    }
    
    int getCount() {
        return count;
    }
    
    // This is easy, just draw all the lines
    void render() {
        for(KochLine l : Lines) {
            l.draw();
        }
    }
    
    // This is where the **MAGIC** happens
    // Step 1: Create an empty arraylist
    // Step 2: For every line currently in the arraylist
    //   - calculate 4 line segments based on Koch algorithm
    //   - add all 4 line segments into the new arraylist
    // Step 3: Return the new arraylist and it becomes the list of line segments for the structure
    
    // As we do this over and over again, each line gets broken into 4 lines, which gets broken into 4 lines, and so on. . .
    vector iterate(vector <KochLine> before) {
        vector <KochLine> now;    // Create emtpy list
        for(KochLine l : before) {
            // Calculate 5 koch ofVec2fs (done for us by the line object)
            ofVec2f a = l.start();
            ofVec2f b = l.kochleft();
            ofVec2f c = l.kochmiddle();
            ofVec2f d = l.kochright();
            ofVec2f e = l.end();
            // Make line segments between all the ofVec2fs and add them
            now.push_back(KochLine(a,b));
            now.push_back(KochLine(b,c));
            now.push_back(KochLine(c,d));
            now.push_back(KochLine(d,e));
        }
        
        return now;
    }
    
};