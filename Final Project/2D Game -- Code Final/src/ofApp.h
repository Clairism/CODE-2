#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSpriteSheetRenderer.h"

//create a new animation. This could be done optinally in your code andnot as a static, just by saying animation_t walkAnimation; walkAnimation.index =0, walkAnimation.frame=0 etc. I find this method the easiest though
static animation_t walkAnimation =
{	0,	/* .index			(int) - this is the index of the first animation frame. indicies start at 0 and go left to right, top to bottom by tileWidth on the spriteSheet		*/
    0,	/* .frame			(int) - this is the current frame. It's an internal variable and should always be set to 0 at init													*/
    4,	/* .totalframes		(int) - the animation length in frames																												*/
    1,	/* .width			(int) - the width of each animation frame in tiles																									*/
    1,	/* .height			(int) - the height of each animation frame in tiles																									*/
    75,	/* .frameduration	(unsigned int) - how many milliseconds each frame should be on screen. Less = faster																*/
    0,	/* .nexttick		(unsigned int) - the next time the frame should change. based on frame duration. This is an internal variable and should always be set to 0 at init	*/
    -1,	/* .loops			(int) - the number of loops to run. -1 equals infinite. This can be adjusted at runtime to pause animations, etc.									*/
    -1,	/* .finalindex		(int) - the index of the final tile to draw when the animation finishes. -1 is the default so total_frames-1 will be the last frame.				*/
    1	/* .frameskip		(int) - the incrementation of each frame. 1 should be set by default. If you wanted the animation to play backwards you could set this to -1, etc.	*/
};

//a quick and dirty sprite implementation
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
		
//    ofxPanel gui;
//    
//    ofxButton button;
//    ofxToggle toggle;

    
    ofPoint playerPos;
    bool changeAnim;

    //create the instance of the spriteSheetRenderer. we only need one.
    ofxSpriteSheetRenderer* spriteRenderer;
    
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
    const int GRIDW = 30;  //width in tiles of the background grid
    const int GRIDH = 30;  //height in tiles of the background grid
    
    bool hasSuit;
    bool isHappy;
    
    bool walkingLeft;
    bool walkingRight;
    
    //lastly, we'll make a simple function that returns which sprite a tile is at a given x and y position
    //this is useful so we can find out which sprites the player is near so we can collide or not, for example.
    int getTileName(int x, int y);
    
    
};

