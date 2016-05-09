#include "ofApp.h"

bool sortVertically(basicSprite * a, basicSprite * b ) {
    return a->pos.y > b->pos.y;
}

// this method will be used to get the index of the sprite the player is standing on, or to check for possible collisions with "solid" tiles.
int ofApp::getTileName(int x, int y) {
    return backgrounds[y * GRIDW + x]->tileName;
}
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(200);
    
//sprites setup
    //set a limited frame rate, enable alpha blending, and set no anti-aliasing for pixel art.
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofDisableAntiAliasing();

    //create the sprite renderer with 2 layers, and 64x64 tiles.
    spriteRenderer = new ofxSpriteSheetRenderer(3, 10000, 0, 128);
    spriteRenderer->loadTexture("Egg game sprite sheet.png", 1024, GL_NEAREST);

    //set position
    playerPos.x = ofGetWidth()/2;
    playerPos.y = ofGetHeight()*2/3;
    
    //create "player" as an instance of our basicSprite struct, then set his position, speed, and default animation.
    player = new basicSprite();
    player->pos.set(playerPos.x, playerPos.y);
    player->speed = 0.5;

    player->animation = normalIdle;
    
    //loop through the grid, make a new sprite background tile
    for (int i = 0; i < GRIDH; i++) {
        for (int j = 0; j < GRIDW; j++) {
            basicSprite * newSprite = new basicSprite();
            newSprite->pos.set(j*spriteRenderer->getTileSize()*BGSCALE, i*spriteRenderer->getTileSize()*BGSCALE);
            newSprite->tileName = 24;
            backgrounds.push_back(newSprite);
        }
    }
    
    hasSuit = false;
    isHappy = false;
    
    walkingLeft = false;
    walkingRight = false;
    
    
//text setup
    
    //textBox.load("TextWindow.png");
    
    myText.init("Helvetica.dfont", 20);
    
    myText.setText("Welcome to my 'Egg' world. Press A, D or Left, Right Arrow to move. Space bar to change clothes. ");
    
    //Initially wrap the text to the screen width
    myText.wrapTextX(2*ofGetWidth()/3);

    indent = 10;
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    if(hasSuit){
//        spriteRenderer->loadTexture("CharacterSuitSheet.png", 256, GL_NEAREST);
//    }else{
//        spriteRenderer->loadTexture("CharacterCasualSheet.png", 256, GL_NEAREST);
//    }
//    
    //clear and update the renderer
    spriteRenderer->clear();
    spriteRenderer->update(ofGetElapsedTimeMillis());

    //add the Link sprite to the renderer.
    spriteRenderer->addCenteredTile(&player->animation, player->pos.x - cameraCenter.x, player->pos.y - cameraCenter.y, 1, F_NONE, SCALE);
    
    //update the player's position and animation index based on key presses.
    if (walkingLeft) {
        player->pos.x -= player->speed * spriteRenderer->getTileSize()*SCALE;
        player->animation.index = 8;
        player->animation.total_frames = 4;
        player->animation.frame_duration = 200;
        
//        player->animation = walkLeft;

    }else if (walkingRight) {
        player->pos.x += player->speed * spriteRenderer->getTileSize()*SCALE;
        player->animation.index = 4;
        player->animation.total_frames = 4;
        player->animation.frame_duration = 200;

    }else if(!isHappy){
        player->animation.index = 0;
        player->animation.total_frames = 2;
        player->animation.frame_duration = 500;
    }else if(isHappy){
        player->animation.index = 2;
        player->animation.total_frames = 2;
        player->animation.frame_duration = 500;
    }
    
  
    //if there are backgrounds, loop through it and add each one to the renderer.
    if (backgrounds.size() > 0) {
        for (int i = backgrounds.size()-1; i>=0; i--) {

          spriteRenderer->addCenteredTile(backgrounds[i]->tileName, 0, backgrounds[i]->pos.x, backgrounds[i]->pos.y, 0, 1, 1, F_NONE, BGSCALE);

        }
    }
    
    //update the background position based on the grid and the camera position.
    for (int i = 0; i < GRIDH; i++) {
        for (int j = 0; j < GRIDW; j++) {
            backgrounds[i * GRIDW + j]->pos.set(j*spriteRenderer->getTileSize()*BGSCALE - cameraCenter.x, i*spriteRenderer->getTileSize()*BGSCALE - cameraCenter.y);
        }
    }
 
    //this is an application of how we could check the player's position against the tiles.
    //we could use this approach to do collision detection for example.
        
    int tilePosX = floor((player->pos.x + (spriteRenderer->getTileSize() * SCALE)/2) / (spriteRenderer->getTileSize() * SCALE));
    int tilePosY = floor((player->pos.y + (spriteRenderer->getTileSize() * SCALE)/2) / (spriteRenderer->getTileSize() * SCALE));
    
//    cout << "pos.x relative to tiles: " <<  tilePosX << ", pos.y relative to tiles: " <<  tilePosY << endl;
//    cout << "background sprite index: " << getTileName(tilePosX, tilePosY) << endl;
    //}
   
    
    //update the camera position to focus on the player's position.
    cameraCenter.x = player->pos.x - ofGetWindowWidth()/2;
    cameraCenter.y = player->pos.y - ofGetWindowHeight()*2/3;

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //textBox.draw(ofPoint(0, ofGetHeight()*2/3), ofGetWidth(), 120 + indent);

//    gui.draw();
    spriteRenderer->draw();
    
    myText.setColor(0, 50, 225, 255);
    myText.drawCenter(ofGetWidth()/2, ofGetHeight()*2/3);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//space bar -- suit
    if(key == ' '){
        if(!hasSuit){
            //wear suit
            hasSuit = true;
        }else{
            //take off suit
            hasSuit = false;
        }
    }
    
//be happy
    
    if(key == 'z'){
        if(!isHappy){
            //wear suit
            isHappy = true;
        }else{
            //take off suit
            isHappy = false;
        }
    }

//movement control
    if (key == 'a' || key == OF_KEY_LEFT){
        walkingLeft = true;
    }
    
    if (key == 'd' || key == OF_KEY_RIGHT){
        if(playerPos.x >= 0){
            walkingRight = true;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (key == 'a' || key == OF_KEY_LEFT){
        walkingLeft = false;
    }
    
    if (key == 'd' || key == OF_KEY_RIGHT){
        walkingRight = false;
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
