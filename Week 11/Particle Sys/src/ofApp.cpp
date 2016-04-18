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
//    ofSetBackgroundAuto(false);
    //p.param.setup();
    time0 = ofGetElapsedTimef();
    bornCount = 0;
    bornRate = 1000;
    
    gui.setup();
    /*    
     eRad = 50;
     velRad = 100;
     lifeTime = 1.0;
     rotate = 90;
     
     force =1000;
     spin = 1000;
     friction = 0.05;
     */
    
    gui.add(rad.setup("Rad", 350, -800, 1000));
    gui.add(velRad.setup("VelRad", 100, -1000, 1000));
    gui.add(lifeTime.setup("lifeTime", 1.0, 1.0, 10.0));
    gui.add(rotate.setup("Rotate", 90, 0, 360));
    
    gui.add(force.setup("Force", 500, -5000, 5000));
    gui.add(spin.setup("Spin", 1000, -2000, 2000));
    gui.add(friction.setup("Friction", 0.15, 0.01, 0.5));
    

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
            newp.param.setup(rad, velRad, lifeTime, timeGui, rotate, force, spin, friction);
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
    
    gui.draw();

    
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
