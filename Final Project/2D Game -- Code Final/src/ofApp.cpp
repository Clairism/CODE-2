#include "ofApp.h"

bool sortVertically(basicSprite * a, basicSprite * b ) {
    return a->pos.y > b->pos.y;
}

// this method will be used to get the index of the sprite the player is standing on, or to check for possible collisions with "solid" tiles.
//int ofApp::getTileName(int x, int y) {
//    return backgrounds[y * GRIDW + x]->tileName;
//}
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
    securityX = ofGetWidth() - 50;
    
    //create "player" as an instance of our basicSprite struct, then set his position, speed, and default animation.
    player = new basicSprite();
    player->pos.set(playerPos.x, playerPos.y);
    player->speed = 0.03;

    player->animation = normalIdle;
    
    security = new basicSprite();
    security->animation = securityIdle;
    
    //loop through the grid, make a new sprite background tile
//    for (int i = 0; i < GRIDH; i++) {
//        for (int j = 0; j < GRIDW; j++) {
//            basicSprite * newSprite = new basicSprite();
//            newSprite->pos.set(j*spriteRenderer->getTileSize()*BGSCALE, i*spriteRenderer->getTileSize()*BGSCALE);
//            newSprite->tileName = 24;
//            backgrounds.push_back(newSprite);
//        }
//    }
    

    cloud.x = ofGetWidth()/2;
    cloud.y = 50;
    
    hasSuit = false;
    isHappy = false;
    isTalking = false;
    
    walkingLeft = false;
    walkingRight = false;
    
    
//text setup
    
    textBox.load("TextWindow.png");
    
//    myText.init("Helvetica.dfont", 30);
//    myText.wrapTextX(2*ofGetWidth()/3);

    indent = 10;
    
    myFont.load("SUBWT.ttf", 90);
//sound setup
    footstep.load("egg footstep.mp3");
    footstep.setSpeed(1.1);
    timer = 0;
    
     //create some clouds
    for(int i = 1 ; i < 50 ; i++)
    {
        basicSprite * newSprite = new basicSprite();
        newSprite->pos.set(cloud.x + i * ofRandom(500, 1000), ofRandom(cloud.y, 200));
        newSprite->animation = bgIdle;
        newSprite->animation.index = (int)ofRandom(26, 28);
        clouds.push_back(newSprite);
    }

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

    spriteRenderer->addCenteredTile(&player->animation, player->pos.x, player->pos.y, 2, F_NONE, SCALE);
    spriteRenderer->addCenteredTile(&security->animation, securityX, playerPos.y, 1, F_NONE, SCALE);

    //background (tilename, frame, x, y, layer, w, h, flipDirection, float scale, int r,g,b,alpha);
    spriteRenderer->addCenteredTile(24, 0, ofGetWidth()/2, 150, 0, 1, 1, F_NONE, BGSCALE);

    //sun
    spriteRenderer->addCenteredTile(25, 0, 100, 100, 0, 1, 1, F_NONE, 1.2 + cos(ofGetElapsedTimef())*0.3);

    //trees
    spriteRenderer->addCenteredTile(29, 0, 60, playerPos.y - 30, 0, 1, 1, F_NONE, SCALE);
    spriteRenderer->addCenteredTile(30, 0, 200, playerPos.y - 30, 0, 1, 1, F_NONE, SCALE);
    spriteRenderer->addCenteredTile(31, 0, 700, playerPos.y - 30, 0, 1, 1, F_NONE, SCALE);
    
    //clouds
    spriteRenderer->addCenteredTile(26, 0, cloud.x, 50, 1, 1, 1, F_NONE, SCALE);
    spriteRenderer->addCenteredTile(27, 0, cloud.x + 500, 150, 1, 1, 1, F_NONE, SCALE);
    spriteRenderer->addCenteredTile(28, 0, cloud.x - 200, 200, 1, 1, 1, F_NONE, SCALE);

    if(clouds.size()>0)
    {
        for(int i=clouds.size()-1;i>=0;i--)
        {
            clouds[i]->pos.x --; //add their speed to their y
            
            if(clouds[i]->pos.x <= -200){ //if they are past the left side of the screen
                delete clouds[i];
                clouds.erase(clouds.begin()+i);
            }
            else{
                spriteRenderer->addCenteredTile(&clouds[i]->animation, clouds[i]->pos.x, clouds[i]->pos.y, 1, F_NONE, SCALE);
            }
        }
    }

    cloud.x --;
    
    //suit store
    if(!isChanging){
        spriteRenderer->addCenteredTile(32, 0, 420, playerPos.y - 50, 0, 1, 1, F_NONE, 3);
    }else if(isChanging){
        spriteRenderer->addCenteredTile(33, 0, 420, playerPos.y - 50, 0, 1, 1, F_NONE, 3);
    }
    
    
    if(playerX >= 420 - 100 && playerX <= 420 + 100){
        canChange = true;
    }else{
        canChange = false;
    }

    //update the player's position and animation index based on key presses.
    if (walkingLeft) {
        if(playerX >= 30){
            player->pos.x -= player->speed * spriteRenderer->getTileSize()*SCALE;
        }
        if(!hasSuit){
            player->animation.index = 8;
        }else if(hasSuit){
            player->animation.index = 20;
        }
        player->animation.total_frames = 4;
        player->animation.frame_duration = 200;
        
//        player->animation = walkLeft;
        if(footstep.isPlaying() == false){
            footstep.play();
        }
    }else if (walkingRight) {
        if(hasSuit){
            //if(playerX <= ofGetWidth() - 30){
                player->pos.x += player->speed * spriteRenderer->getTileSize()*SCALE;
            //}
        }else{
            if(playerX <= securityX - 60){
                player->pos.x += player->speed * spriteRenderer->getTileSize()*SCALE;
            }
        }
        if(!hasSuit){
            player->animation.index = 4;
        }else if(hasSuit){
            player->animation.index = 16;
        }
        player->animation.total_frames = 4;
        player->animation.frame_duration = 200;
        
        if(footstep.isPlaying() == false){
            footstep.play();
        }

    }else{
        if(!hasSuit){
            player->animation.index = 0;
        }else if(hasSuit){
            player->animation.index = 12;
        }
        player->animation.total_frames = 2;
        player->animation.frame_duration = 500;
    }
//    else if(isHappy){
//        player->animation.index = 2;
//        player->animation.total_frames = 2;
//        player->animation.frame_duration = 500;
//    }
    
  
    //if there are backgrounds, loop through it and add each one to the renderer.
//    if (backgrounds.size() > 0) {
//        for (int i = backgrounds.size()-1; i>=0; i--) {
//
//          spriteRenderer->addCenteredTile(backgrounds[i]->tileName, 0, backgrounds[i]->pos.x, backgrounds[i]->pos.y, 0, 1, 1, F_NONE, BGSCALE);
//
//        }
//    }
    
    
    //update the background position based on the grid and the camera position.
//    for (int i = 0; i < GRIDH; i++) {
//        for (int j = 0; j < GRIDW; j++) {
//
//             backgrounds[i * GRIDW + j]->pos.set(j*spriteRenderer->getTileSize()*BGSCALE, i*spriteRenderer->getTileSize()*BGSCALE);
//        }
//    }
    
    playerX = player -> pos.x;
    
    if(playerX >= securityX - 80){
        canTalk = true;
    }else{
        canTalk = false;
    }
    
    if(isTalking){
        
        spriteRenderer->addCenteredTile(37, 0, ofGetWidth()/2 - myFont.stringWidth("Enjoy yourself!")/2, ofGetHeight() - 200, 3, 1, 1, F_NONE, SCALE);

    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    textBox.draw(ofPoint(ofGetWidth()/2, ofGetHeight() - 200), 200, 300);
//    gui.draw();
    spriteRenderer->draw();
    
//    myText.setColor(255, 255, 255, 255);
//    myText.drawCenter(ofGetWidth()/2, ofGetHeight() - 200);

    if(isTalking){
        //ofSetColor(255, 255, 255, 20);
        //textBox.draw(ofPoint(ofGetWidth()/2 - myText.getWidth()/2, ofGetHeight() - 200), myText.getWidth(), myText.getHeight() * 5);
        textBox.draw(ofPoint(ofGetWidth()/2, ofGetHeight() - 200), 200, 300);

       // myText.setColor(255, 255, 0, 255);
        myFont.load("SUBWT.ttf", 20);
        myFont.drawString("Enjoy yourself!", ofGetWidth()/2 - myFont.stringWidth("Enjoy yourself!")/2, ofGetHeight() - 200);

        if(!hasSuit){
           // myText.setColor(0, 0, 0, 255);
//            myText.drawCenter(ofGetWidth()/2, ofGetHeight() - 200);
            //myFont.drawString("Security: You Can't enter without proper clothes!", ofGetWidth()/2, ofGetHeight()/2);

//            myText.setText("Security: You Can't enter without proper clothes!");
        }else if(hasSuit){
            //myText.setText("Enjoy yourself!");
            //myFont.s
            //myFont.drawString("Enjoy yourself!", ofGetWidth()/2, ofGetHeight()/2);

        }
    }
    
    
    if(playerX >= ofGetWidth()){
        ofSetColor(255, 0, 0, 255);
        myFont.drawString("You Win!", ofGetWidth()/2 - myFont.stringWidth("You Win!")/2, ofGetHeight()/3);
    }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//space bar -- suit
    if(key == ' ' && canChange){
        
        isChanging = true;
        //Changed = true;
        
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
    
    //talk
    if (key == 'e' && canTalk){
//        cout<< canTalk << endl;
        isTalking = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == ' '){
        isChanging = false;
        if(!isChanging){
            Changed = true;
        }
    }

    if (key == 'a' || key == OF_KEY_LEFT){
        walkingLeft = false;
    }
    
    if (key == 'd' || key == OF_KEY_RIGHT){
        walkingRight = false;
    }
    
    if(key == OF_KEY_RETURN){

        isTalking = false;
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
