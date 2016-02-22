#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    flyChange = 0;
    
    Flying.closeWings();
    Team.closeWings();
    SecondTeam.closeWings();


}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(125);
    
    Flying.draw(3*ofGetWidth()/4, ofGetHeight()/2 + flyChange);
    Team.draw(ofGetWidth()/3, ofGetHeight()/2 + flyChange);
    SecondTeam.draw(3*ofGetWidth()/4, 3*ofGetHeight()/4 + flyChange);


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
    
    flyChange = 50;

    Flying.openWings();
    Team.openWings();
    SecondTeam.openWings();


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    flyChange = 0;

    Flying.closeWings();
    Team.closeWings();
    SecondTeam.closeWings();


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
