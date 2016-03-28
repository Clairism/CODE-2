#pragma once

#include "ofMain.h"
#include "KochLine.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    //KochLine startLine;
    
    vector <KochLine> Lines;
    
    ofVec2f start;
    ofVec2f end;

    
    void generate() {
        
        vector <KochLine> next;

        for (KochLine l : Lines) {
            // Calculate 5 koch ofVec2fs (done for us by the line object)
            ofVec2f a = l.kochA();
            ofVec2f b = l.kochB();
            ofVec2f c = l.kochC();
            ofVec2f d = l.kochD();
            ofVec2f e = l.kochE();
            // Make line segments between all the ofVec2fs and add them
            next.push_back(KochLine(a, b));
            next.push_back(KochLine(b, c));
            next.push_back(KochLine(c, d));
            next.push_back(KochLine(d, e));
            
        }
        
        Lines = next;
    };
};
