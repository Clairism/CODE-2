#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // ofSetBackgroundAuto(false);
    ofSetFrameRate(1);
    
    me.dotSize = 8;
    me.offSetAngleA = ofDegToRad(1.5);
    me.offSetAngleB = ofDegToRad(50);
    
    gui.setup();
    gui.add(dotSizeGui.setup("dotsize", 8, 1, 14));
    gui.add(angleA.setup("angleA", 1.5, 1, 5));
    gui.add(angleB.setup("angleB", 50, 1, 360));
    
    //    SOLVING -- variable "angle" -> controls the direction of the entire tree
    gui.add(angle.setup("angle", 270, 1, 360));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight());
    //me.seed1(me.dotSize, ofDegToRad(270), 0, 0);
    
    //    SOLVING -- variable "angle"
    me.seed1(me.dotSize, ofDegToRad(angle), 0, 0);
    
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
