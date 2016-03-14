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
    ofImage fanBase;
    
    float imageX, imageY;
    float imgSize;

    float offSet;
    float offSetAngle;
    
    float quillSize;

    //Feathers from left to right
    Feather Feather1;
    Feather Feather2;
    Feather Feather3;
    Feather Feather4;
    Feather Feather5;
    Feather Feather6;
    Feather Feather7;

    ofxFloatSlider quillAngle;
    ofxPanel gui;

//    ofxFloatSlider barbSize;
//    ofxFloatSlider barbAngle;
};
