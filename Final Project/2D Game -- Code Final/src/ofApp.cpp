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
    
    //set a limited frame rate, enable alpha blending, and set no anti-aliasing for more pixel arty kind of vibe.
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofDisableAntiAliasing();

    //create the sprite renderer with 2 layers, and 16x16 tiles.
    spriteRenderer = new ofxSpriteSheetRenderer(2, 10000, 0, 64);
    
    //load in the 64x64 pixels texture.
    spriteRenderer->loadTexture("CharacterCasualSheet.png", 256, GL_NEAREST);
    
    playerPos.x = ofGetWidth()/2;
    playerPos.y = ofGetHeight()/2;
    
    //create "player" as an instance of our basicSprite struct, then set his position, speed, and default animation.
    player = new basicSprite();
    player->pos.set(playerPos.x, playerPos.y);
    player->speed = 0.5;

    player->animation = normalIdle;
    
    //override default index
//    player->animation.index = 0;
    
    //loop through the grid, make a new sprite for each background tile we want,
    //et its position based on the grid and our scale, push it to the vector.
    //we'll be looping through the vector to access these sprites' values.
    for (int i = 0; i < GRIDH; i++) {
        for (int j = 0; j < GRIDW; j++) {
            basicSprite * newSprite = new basicSprite();
            newSprite->pos.set(j*spriteRenderer->getTileSize()*SCALE, i*spriteRenderer->getTileSize()*SCALE);
            newSprite->tileName = (int)ofRandom(8,12);
            backgrounds.push_back(newSprite);
        }
    }
    
    hasSuit = false;
    isHappy = false;
    
    walkingLeft = false;
    walkingRight = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(hasSuit){
        spriteRenderer->loadTexture("CharacterSuitSheet.png", 256, GL_NEAREST);
    }else{
        spriteRenderer->loadTexture("CharacterCasualSheet.png", 256, GL_NEAREST);
    }
    
    //clear and update the renderer
    spriteRenderer->clear();
    spriteRenderer->update(ofGetElapsedTimeMillis());
    
    //add the Link sprite to the renderer.
    spriteRenderer->addCenteredTile(&player->animation, player->pos.x - cameraCenter.x, player->pos.y - cameraCenter.y, 1, F_NONE, SCALE);
    
    //if there are backgrounds, loop through it and add each one to the renderer.
    if (backgrounds.size() > 0) {
        for (int i = backgrounds.size()-1; i>=0; i--) {
            //this line isn't necessary and in fact is imperfect, but uncomment to see how we might limit drawing to only the current screen area.
            //if (backgrounds[i]->pos.x > 0 && backgrounds[i]->pos.x < ofGetWindowWidth() && backgrounds[i]->pos.y > 0 && backgrounds[i]->pos.y < ofGetWindowHeight()) {
            //spriteRenderer->addCenteredTile(backgrounds[i]->tileName, 0, backgrounds[i]->pos.x, backgrounds[i]->pos.y, 0, 1, 1, F_NONE, SCALE);
            //}
        }
    }
    
    //update the background position based on the grid and the camera position.
    for (int i = 0; i < GRIDH; i++) {
        for (int j = 0; j < GRIDW; j++) {
            backgrounds[i * GRIDW + j]->pos.set(j*spriteRenderer->getTileSize()*SCALE - cameraCenter.x, i*spriteRenderer->getTileSize()*SCALE - cameraCenter.y);
        }
    }
    
    //update the player's position and animation index based on key presses.
    if (walkingLeft) {
        player->pos.x -= player->speed * spriteRenderer->getTileSize()*SCALE;
        player->animation.index = 8;
//        player->animation = walkLeft;
        player->animation.total_frames = 4;

    }else if (walkingRight) {
        player->pos.x += player->speed * spriteRenderer->getTileSize()*SCALE;
        player->animation.index = 4;
        player->animation.total_frames = 4;

    }else{
        player->animation.index = 0;
    }
    
    //if no keys are being pressed, stop animating.
    //if keys are being pressed, animate Link's sprite.
        
        //this is an application of how we could check the player's position against the tiles.
        //we could use this approach to do collision detection for example.
        
        int tilePosX = floor((player->pos.x + (spriteRenderer->getTileSize() * SCALE)/2) / (spriteRenderer->getTileSize() * SCALE));
        int tilePosY = floor((player->pos.y + (spriteRenderer->getTileSize() * SCALE)/2) / (spriteRenderer->getTileSize() * SCALE));
        
//        cout << "pos.x relative to tiles: " <<  tilePosX << ", pos.y relative to tiles: " <<  tilePosY << endl;
//        
//        cout << "background sprite index: " << getTileName(tilePosX, tilePosY) << endl;
    //}
    
    //update the camera position to focus on the player's position.
    cameraCenter.x = player->pos.x - ofGetWindowWidth()/2;
    cameraCenter.y = player->pos.y - ofGetWindowHeight()/2;
    
    
  /*
    if(hasSuit){
        spriteRenderer->loadTexture("CharacterSuitSheet.png", 256, GL_NEAREST);
    }else{
        spriteRenderer->loadTexture("CharacterCasualSheet.png", 256, GL_NEAREST);
    }

    spriteRenderer->clear(); // clear the sheet
    spriteRenderer->update(ofGetElapsedTimeMillis()); //update the time in the renderer, this is necessary for animations to advance
    
    sort( sprites.begin(), sprites.end(), sortVertically ); // sorts the sprites vertically so the ones that are lower are drawn later and there for in front of the ones that are higher up
//    spriteRenderer->addTile(0, playerPos.x, playerPos.y);

    
    if(sprites.size()>0) // if we have sprites
    {
        for(int i=sprites.size()-1;i>=0;i--) //go through them
        {
//            sprites[i]->pos.y += sprites[i]->speed; //add their speed to their y
            //display in pos.y
            sprites[i]->pos.y;
            
   
            if(sprites[i]->pos.y > ofGetHeight()+16) //if they are past the bottom of the screen
            {
                delete sprites[i]; //delete them
                sprites.erase(sprites.begin()+i); // remove them from the vector
            }

//            else
            
            spriteRenderer->addCenteredTile(&sprites[i]->animation, sprites[i]->pos.x, sprites[i]->pos.y); // add them to the sprite renderer (add their animation at their position, there are a lot more options for what could happen here, scale, tint, rotation, etc, but the animation, x and y are the only variables that are required)
       }
    }
    
    
    
    for(int i=0;i<10;i++){
        
        basicSprite * newSprite = new basicSprite(); // create a new sprite
        
        newSprite->pos.set(playerPos.x ,playerPos.y); //set its position
        newSprite->speed=0.5; //set its speed (higher = faster)
        
        //set its animation (different modes)

        if(walkingLeft || walkingRight){
            
            if(walkingLeft){
                newSprite->animation = walkLeft;
            }
            
            if(walkingRight){
                newSprite->animation = walkRight;
            }

        }else{
            newSprite->animation = normalIdle;
        }
        
        newSprite->animation.frame_duration /= newSprite->speed; //change frame duration
        
        newSprite->animation.index = (int)ofRandom(0,2)*8; //change the start index of our sprite. we have 4 rows of animations and our spritesheet is 8 tiles wide, so our possible start indicies are 0, 8, 16, and 24
        sprites.push_back(newSprite); //add our sprite to the vector
    }
    
    */
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    gui.draw();
    spriteRenderer->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == ' '){
        if(!hasSuit){
            //wear suit
            hasSuit = true;
        }else{
            //take off suit
            hasSuit = false;
        }
    }

    
    if (key == 'a' || key == OF_KEY_LEFT){
        walkingLeft = true;
    }
    
    if (key == 'd' || key == OF_KEY_RIGHT){
        walkingRight = true;
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
