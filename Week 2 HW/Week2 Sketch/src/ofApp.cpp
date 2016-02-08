#include "ofApp.h"


void ofApp:: creature(ofPoint center, float size){
    
    //face
    
    ofSetColor(255,255,0);
    ofFill();
    
    ofDrawRectangle(center.x - size/2, center.y - size/3, size, 2*size/3);
    
    //eyes
    
    ofSetColor(0,200,255);
    ofSetLineWidth(5);
    
    ofDrawRectangle(center.x - size/4 - 40, center.y - 2*size/9, 80,60);
    ofDrawRectangle(center.x + size/4 - 40, center.y - 2*size/9, 80,60);
    
    
    if(clicked){
        
        ofSetColor(255,0,0);
        
        ofDrawLine(center.x-size/5, center.y + size/9, center.x, center.y + size/6);
        ofDrawLine(center.x, center.y + size/6, center.x+size/5, center.y + size/9);
        
    }else{
        
        ofDrawLine(center.x-size/5, center.y + size/6, center.x+size/5, center.y + size/10);
        
    }


}

void ofApp:: movingCreature(ofPoint center, float size){
    
    if(clicked){
        ofSetColor(225,130,175);
    }else{
        ofSetColor(225,0,150);
    }
    
    ofFill();

    ofDrawEllipse(center.x - 2*size/3, center.y + size/6, size/2, size/2);
    ofDrawEllipse(center.x + 2*size/3, center.y + size/6, size/2, size/2);

}



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    ofEnableSmoothing();
    ofSetFrameRate(25);
    
    monster.x = ofGetWidth()/2;
    monster.y = ofGetHeight()/2;
    
    monsterSize = 350;
    
    creature(monster, monsterSize);
    movingCreature(monster, monsterSize);
    
    clicked = false;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    monster.x = mouseX;
    monster.y = mouseY;
    
    creature(monster, monsterSize);
    
    movingCreature(monster, monsterSize);
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    clicked = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    clicked = false;

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

