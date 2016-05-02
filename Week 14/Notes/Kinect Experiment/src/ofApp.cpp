#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(threshHoldNear.setup("Near Threshold", 170, 0, 255));
    gui.add(threshHoldFar.setup("Far Threshold", 100, 0, 255));
    
    
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    angle = 15;
    kinect.setCameraTiltAngle(angle);
    
    colorImg.allocate(kinect.width, kinect.height);
    grayImage.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    
    bThreshOpenCV = true;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    nearThreshHold = threshHoldNear;
    farThreshHold = threshHoldFar;
    
    kinect.update();
    kinect.setCameraTiltAngle(angle);
    
    if(kinect.isFrameNew()){
        grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
        
        
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(nearThreshHold);
        grayThreshFar.threshold(farThreshHold);
        cvAnd(grayThreshFar.getCvImage(), grayThreshNear.getCvImage(), grayImage.getCvImage());
    }
    
    contourFinder.findContours(grayImage, 10, (kinect.width*kinect.height)/4, 2, false);
    
    cursors.clear();
    
    
    for(int i = 0; i < contourFinder.nBlobs; i++){
        
        ofPoint center = contourFinder.blobs[i].centroid;
        cursors.push_back(center);
        
    }

}
//--------------------------------------------------------------
void ofApp::draw(){
    
    //kinect.draw(0, 20, 400, 400);
    //kinect.drawDepth(0, 280, 400, 400);
    
    grayImage.draw(0, 0, kinect.width, kinect.height);
    contourFinder.draw(0, 0, kinect.width, kinect.height);
    gui.draw();
    
    
    if(cursors.size()>0){
        for(int i = 0; i< cursors.size(); i++){
            
            ofSetColor(255, 0, 0);
            ofCircle(cursors[i], 10);
            
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
            
        case OF_KEY_UP:
            angle ++;
            if (angle == 30) {
                angle = 30;
            }
            break;
            
        case OF_KEY_DOWN:
            angle --;
            if (angle <= 0) {
                angle = 0;
            }
            break;
            
        default:
            break;
    }

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
