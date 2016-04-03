#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //ofSetBackgroundAuto(false);
    amplitude = ofGetHeight()/2;
    
    period = 25;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    circleX = ofGetElapsedTimef() * period;
    circleY = amplitude * sin(ofGetElapsedTimef());
    circle2Y = amplitude * sin(ofGetElapsedTimef() + PI);
    
    float sine = sin(ofGetElapsedTimef()); //btw -1 & 1

    mapX = ofMap(sine, -1, 1, 0, ofGetWidth());
    mapY = ofMap(sine, -1, 1, 0, ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(120, 255, 255);
    ofFill();
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, mapX, mapY);

    ofTranslate(0, ofGetHeight()/2);
    
    ofSetColor(255, 255, 0);
    ofFill();
    ofDrawEllipse(circleX, circleY, 15, 15);
    
    ofSetColor(80, 200, 255);
    ofFill();
    ofDrawEllipse(circleX, circle2Y, 10, 10);
    
 //   ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, mapX, mapY);
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
