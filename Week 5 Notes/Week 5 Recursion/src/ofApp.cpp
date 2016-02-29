#include "ofApp.h"


void ofApp:: drawBranch(float length, float theta){
    
    ofSetLineWidth(3);

    ofDrawLine(0, 0, 0, -length);
    ofTranslate(0, -length);
    
    length = length * 0.4;

    //won't crash
    if (length > 2) {

        ofPushMatrix();     //always rotate inside a confined space
        ofRotate(theta);    //degrees
        drawBranch(length, theta);
        ofPopMatrix();
        
        //the other direction
        ofPushMatrix();
        ofRotate(-theta);
        drawBranch(length, theta);
        ofPopMatrix();
        
    }
}

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    
    xPos += 2;
    if(ofGetWidth()<xPos){  // if vertical position is off the screen (width)
        xPos = 10;            // reset vertical position
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255, 255, 0);
    ofFill();
    
    ofTranslate(xPos, ofGetHeight());

    drawBranch(400, cos(ofGetElapsedTimef())*180);      //cos -- let the branch move

//    ofDrawLine(0, 0, 0, -length);
//    
//    ofTranslate(0, -length);
//    ofRotate(30);
//    ofDrawLine(0, 0, 0, -length);
    
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
