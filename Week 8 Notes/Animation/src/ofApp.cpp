#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    pct = 0;
    
    cc.pos.x = 10;
    cc.pos.y = 10;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += 0.01f;
    
    if(pct >= 1){
        pct = 0;
    }

    //cc.interpolate(pct);
    cc.zeno(ofGetWidth()-10, 10);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cc.draw();

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
