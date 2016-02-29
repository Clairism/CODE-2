#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //keep background the same(?)
    ofSetBackgroundAuto(false);

    
    current = "A";//generation 0 / axiom
    next = "";//existing state of generation 1
    
    counter = 0;//number of generation
    mover = 10;//y position
    
    screenText = false;

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(screenText == true){
        
        ofDrawBitmapString("generation" + ofToString(counter) + ": " + current, 10, mover);
        
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
    
    for(int i = 0; i < current.size(); i++){
        
        char checker = current[i]; //character
        
        
    //rules
        if(checker == 'A'){
         
            next += "AB";
            
        }else if (checker == 'B'){
            
            next += "A";
            
        }
        
    }
    
    current = next;
    counter ++;
    mover += 10;
    screenText = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    screenText = false;

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
