#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    //    ofSetLineWidth(5);
    
    ofVec2f a;
    a.set(0, ofGetHeight()/2);
    ofVec2f b;
    b.set(ofGetWidth(), ofGetHeight()/3);
    ofVec2f c;
    c.set(ofGetWidth()/2, 100+ofGetWidth()/2*cos(ofDegToRad(30)));
    
    // Starting with additional lines
    Lines.push_back(KochLine(a, b));
    Lines.push_back(KochLine(b, c));
    Lines.push_back(KochLine(c, a));
    
    
    for (int i = 0; i < 5; i++) {
        generate();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //startLine.draw();
    
    for (KochLine l : Lines) {
        l.draw();
        
        //cout << l.kochC() << endl;
    }
    
    
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
