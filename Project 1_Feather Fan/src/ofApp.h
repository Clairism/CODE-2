#pragma once

#include "ofMain.h"
#include "Feather.hpp"
#include "ofxGui.h"

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
    
    //get image of fan's base
    
    //Feathers from left to right
    Feather First;
    Feather Second;
    Feather Third;
    Feather Fourth;
    Feather Fifth;
    
    ofxFloatSlider angle;
    ofxFloatSlider barbSize;
    ofxFloatSlider quillLength;
    ofxPanel gui;

		
};
