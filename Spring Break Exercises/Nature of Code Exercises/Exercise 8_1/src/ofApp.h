#pragma once

#include "ofMain.h"

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
    
    
    void drawIt(float x, float y, float length) {
        
        ofNoFill();

        //ofDrawRectangle(x, y, length, length/3);
        ofDrawCircle(x, y, length/2);
        
        cantor(ofGetWidth()/2, ofGetHeight()/2, 20);

        if(length > 2) {
            drawIt(x + length/2, y + length/2, length/3);
            drawIt(x - length/2, y - length/2, length/3);
            drawIt(x + length/2, y, length/2);
            drawIt(x - length/2, y, length/2);
        }
    }
    
    void cantor(float x, float y, float r) {
        
        if (r >= 1) {
            
            ofDrawCircle(x,y,r);
            y += 20;
            cantor(x,y,r/3);
            cantor(r*2/3,y,r/3);
        } }
		
};
