#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    Flying.closeWings();
    flyChange = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(125);
    ofSetColor(0);
    
    Flying.draw(3*ofGetWidth()/4, ofGetHeight()/2 + flyChange);

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
    
    Flying.openWings();
    flyChange = 50;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    Flying.closeWings();
    flyChange = 0;


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
