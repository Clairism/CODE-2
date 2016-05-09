#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSpriteSheetRenderer.h"
#include "ofxTextSuite.h"

struct basicSprite {
    animation_t animation;	// a variable to store the animation this sprite uses
    ofPoint pos;			// the position on the screen this sprite will be drawn at
    float speed;			// the speed at which this sprite moves down the screen
    int tileName;
};

static animation_t normalIdle = {
    0,  //.index (starts drawing at index 0 on the spritesheet)
    0,  //.frame
    2,  //.totalframes  (2 frames in this animation)
    1,  //.width
    1, //.height
    500, //.frameduration
    0,  //.nexttick
    -1, //.loops (infinite loops)
    0, //.finalindex
    1   //.frameskip
};
/*
static animation_t happyIdle = {
    2,  //.index of the first animation
    0,  //.frame
    2,  //.totalframes
    1,  //.width
    1,  //.height
    500, //.frameduration
    0,  //.nexttick
    -1, //.loops
    2, //.finalindex
    1   //.frameskip
};

static animation_t walkRight = {
    4,  //.index of the first animation
    0,  //.frame
    4,  //.totalframes
    1,  //.width
    1,  //.height
    200, //.frameduration
    0,  //.nexttick
    -1, //.loops
    0, //.finalindex
    1   //.frameskip
};

static animation_t walkLeft = {
    8,  //.index of the first animation
    0,  //.frame
    4,  //.totalframes
    1,  //.width
    1,  //.height
    200, //.frameduration
    0,  //.nexttick
    -1, //.loops
    0, //.finalindex
    1   //.frameskip
};
*/
static animation_t securityIdle = {
    35,  //.index of the first animation
    0,  //.frame
    2,  //.totalframes
    1,  //.width
    1,  //.height
    200, //.frameduration
    0,  //.nexttick
    -1, //.loops
    35, //.finalindex
    1   //.frameskip
};

static animation_t bgIdle = {
    0,  //.index of the first animation
    0,  //.frame
    1,  //.totalframes
    1,  //.width
    1,  //.height
    500, //.frameduration
    0,  //.nexttick
    -1, //.loops
    0, //.finalindex
    1   //.frameskip
};


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
    
    //bool changeAnim;

    ofxSpriteSheetRenderer* spriteRenderer;

    //create an instance of basicSprite struct (store player information)
    basicSprite * player;
    basicSprite * security;

//    vector<basicSprite *> backgrounds;
    vector<basicSprite *> clouds;
    
    const float SCALE = 2; //constant to store our sprite scaling value
    const float BGSCALE = 10; //constant to store our sprite scaling value
//    const int GRIDW = 30;  //width in tiles of the background grid
//    const int GRIDH = 30;  //height in tiles of the background grid
    
    //returns tile index
    int getTileName(int x, int y);
    
    ofPoint playerPos;
    float securityX;
    float playerX;
    ofPoint cloud;
    float sunScale;
    
    bool canChange;
    bool isChanging;
    bool Changed;
    bool hasSuit;
    
    bool isHappy;
    
    bool canTalk;
    bool isTalking;
    
    bool walkingLeft;
    bool walkingRight;
    
    //dialog
    ofTrueTypeFont myFont;
    ofxTextBlock        myText;
    TextBlockAlignment  alignment;  //constants for controlling state
    
    ofImage textBox;
    float indent;
    
    ofSoundPlayer footstep;
    float timer;
};

