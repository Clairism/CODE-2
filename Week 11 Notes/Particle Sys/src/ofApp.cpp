#include "ofApp.h"

/*
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    p.param.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    time = ofGetElapsedTimef();
    float dt = ofClamp(time, 0, 0.1);
    if(!p.live){
        p.setup();
    }
    
    p.update(dt);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    p.draw();
}
*/

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetBackgroundAuto(false);
    //p.param.setup();
    time0 = ofGetElapsedTimef();
    bornCount = 0;
    bornRate = 1000;
}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef();
    float dt = ofClamp(time - time0, 0, 0.1);
    time0 = time;
    
    //delete dead particles
    for(int i = 0; i < p.size(); i++){
        if(!p[i].live){
            p.erase(p.begin() + i);
        }
    }
    
    bornCount += bornRate*dt;
    //birth new particles
    if(bornCount >= 1){
        int bornN = int(bornCount);
        bornCount -= bornN;
        for(int i=0; i<bornN; i++){
            Particle newp;
            newp.param.setup();
            newp.setup();
            p.push_back(newp);
        }
    }
    
    // creat new particles
    
    for(int i=0; i<p.size(); i++){
        p[i].update(dt);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i=0; i<p.size(); i++){
        p[i].draw();
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
