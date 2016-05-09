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
    
    ofPoint playerPos;
    bool changeAnim;

    //create the instance of the spriteSheetRenderer. we only need one.
    ofxSpriteSheetRenderer* spriteRenderer;
    ofxSpriteSheetRenderer* textWindow;

    //create an instance of our basicSprite struct that we'll use to store player information
    //(this is technically a pointer to a basicSprite object but we use it essentially the same as we would if it was the object itself)
    basicSprite * player;
    
    //a vector is a C++ data structure like an array, except dynamic and powerful like a Java ArrayList.
    //we'll use this vector to store basicSprite structs for all our background tiles.
    vector<basicSprite *> backgrounds;
    
    //instead of just moving the player around on a static background, lets move a "camera" position along with the player.
    //this will move all the background tiles relative to the camera, making the world appear to move around the player's perspective.
    ofPoint cameraCenter;
    
    const float SCALE = 2; //constant to store our sprite scaling value
    const float BGSCALE = 12; //constant to store our sprite scaling value
    const int GRIDW = 30;  //width in tiles of the background grid
    const int GRIDH = 30;  //height in tiles of the background grid
    

    bool hasSuit;
    bool isHappy;
    
    bool walkingLeft;
    bool walkingRight;
    
    //lastly, we'll make a simple function that returns which sprite a tile is at a given x and y position
    //this is useful so we can find out which sprites the player is near so we can collide or not, for example.
    int getTileName(int x, int y);
    
    //dialog
    ofxTextBlock        myText;
    TextBlockAlignment  alignment;  //constants for controlling state
    
    ofImage textBox;
    float indent;
};

