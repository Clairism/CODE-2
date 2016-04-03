#include "ofApp.h"

void ofApp::zeno(float catchX, float catchY){

    pos.x = speed * catchX + (1 - speed)*pos.x;
    pos.y = speed * catchY + (1 - speed)*pos.y;
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetBackgroundAuto(false);
    ofBackground(0);
    speed = 0.05;
    
    pct = 0;
    
    pos.x = 10;
    pos.y = 10;
}

//--------------------------------------------------------------
void ofApp::update(){
    

    pct += 0.01f;
    
    if(pct >= 1){
        pct = 0;
    }
    
    zeno(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 255, 0);
    ofFill();
    ofDrawCircle(pos.x, pos.y, 20);
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
