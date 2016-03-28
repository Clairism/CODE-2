#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    float myPct;
    myPct = .04;
    
    posY = 0;
    posX = ofGetWidth();
    
    pct = powf(myPct,2);

    //direction changer
    x = 1;
    y = 0;
    
}

//--------------------------------------------------------------

void ofApp::update(){
    
    //if we want something to move we must increase it
    //making the pct number smaller will slow the sq down (try .01)
    
    pct +=0.01* x;
    
    if (pos.x >= ofGetWidth()){
    
        x = -1;
        
    }else if (pos.x <= 0){
        
        x = 1;
        
    }
    
    pos.x = (1-pct)*posY+pct*posX;
    
    y *= cos(ofGetWidth());

    if(pos.x == ofGetWidth()/2){
        y *= sin(ofGetWidth());
    }
    
    pos.y= ofGetWidth()/2 + y;

    
}

//--------------------------------------------------------------

void ofApp::draw(){
    
    ofDrawCircle(pos.x,pos.y, 15);
    
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
