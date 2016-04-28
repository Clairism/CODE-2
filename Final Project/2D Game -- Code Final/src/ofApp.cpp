#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setDefaultBackgroundColor(ofColor(255, 255, 0));
    gui.setDefaultWidth(800);
    gui.setDefaultHeight(100);
    gui.setDefaultFillColor(0);
    gui.setDefaultBorderColor(ofColor(255));
    gui.loadFont(20);
    gui.loadFont(<#const std::string &filename#>, <#int fontsize#>)
    //gui.setPosition(ofGetWidth()/2, ofGetHeight()/2);
    gui.setName("Dialogue");
    
    gui.setup();
    
    gui.add(button.setup("Button"));
    gui.add(toggle.setup("Toggle", true));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    
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
