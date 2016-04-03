#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetBackgroundAuto(false);
    
    posA.x = 0;
    posA.y = ofGetWidth();
    
    //direction changer
    x = 1;
    
    //longest length
    y = ofGetHeight()/2;
    
    //cout << pct << endl;
    
}

//--------------------------------------------------------------

void ofApp::update(){
    
    //if we want something to move we must increase it
    //making the pct number smaller will slow the sq down (try .01)
    
    
    //going back and forth
    pct += 0.01 * x;
    
    if (pos.x >= ofGetWidth()){
    
        x = -1;
        
    }else if (pos.x <= 0){
        
        x = 1;
        
    }
    
    pos.x = (1-pct) * posA.x + pct * posA.y;
    
    //swing
   // cout << myPct << endl;


    if(pos.x <= ofGetWidth()/2){
        
        myPct = powf(0.01, pct);

    }else{

        myPct = powf(0.01, (1 - pct));

    }

    pos.y = (1 - myPct) * y;


}

//--------------------------------------------------------------

void ofApp::draw(){
    
    ofSetColor(0);
    ofFill();
    
    ofDrawLine(pos.x, pos.y, ofGetWidth()/2, 0);
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
