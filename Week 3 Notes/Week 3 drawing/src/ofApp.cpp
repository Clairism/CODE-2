#include "ofApp.h"
//#include "Claire.hpp"

/* string exercises

void ofApp::drawWord(string word){
    ofDrawBitmapString(word, ofGetWidth()/2, ofGetWidth()/2);
    
}
 */
//--------------------------------------------------------------
void ofApp::setup(){
    /* string exercises
    phrase = "Hello Claire";
    position.x = ofGetWidth()/2;
    position.y = ofGetHeight()/2;
     */
    
    Dyberal.smell = "good";
    Dyberal.height = 30;
    Dyberal.name = "Doo";
    Nighttac.height = 50;
    
    Dyberal.r = 0; Dyberal.g = 175; Dyberal.b = 255;
    Nighttac.r = 255; Nighttac.g = 255; Nighttac.b = 0;


}

//--------------------------------------------------------------
void ofApp::update(){
    
    cout << "Dyberal smell:" << Dyberal.smell << endl;
    cout << "Dyberal height:" << Dyberal.height << endl;
    cout << "Dyberal name:" << Dyberal.name << endl;


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /* string exercises

    ofBackground(255);
    ofSetColor(255, 0, 0);
    
    //ofDrawBitmapString("Hello Claire", ofGetWidth()/2, ofGetHeight()/2);
    //ofDrawBitmapString(phrase, position);
    drawWord(phrase);
     */
    
    Nighttac.draw(ofGetWidth()/2 - 2*Nighttac.height, ofGetHeight()/2);
    Dyberal.draw(ofGetWidth()/2, ofGetHeight()/2);

    
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
