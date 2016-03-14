#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFullscreen(true);
    
    fanBase.load("images/fan base.png");
    offSet = 18;
    offSetAngle = ofDegToRad(30);
    
    quillSize = 8;
    imgSize = quillSize*75;

    gui.setup();
    gui.add(quillAngle.setup("FeatherAngle", PI/2, ofDegToRad(50), ofDegToRad(130)));

    //gui.add(barbSize.setup("BarbSize", 8, 1, 14));
    //gui.add(quillSize.setup("FeatherSize", 8, 5, 10));
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetBackgroundColor(0);

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight());
    
    ofRotate(quillAngle * -3, 0, 0, 1);
    fanBase.draw( -imgSize/2, -imgSize/2 - offSet*10, imgSize , imgSize);

    ofRotate(quillAngle);
    Feather1.growQuill(quillSize, -quillAngle - 2*offSetAngle, -imgSize/2 + 2*offSet/3, -imgSize/2 + offSet*7.3);
    Feather2.growQuill(quillSize, -quillAngle - 3*offSetAngle/2, -imgSize/3 - 2*offSet/3, -imgSize/2 + offSet*3);
    Feather3.growQuill(quillSize, -quillAngle - 2*offSetAngle/3, -imgSize/5 - offSet/3, -imgSize/2 - offSet);
    Feather4.growQuill(quillSize, -quillAngle, 0 - offSet, -imgSize/2 - offSet*3);
    Feather5.growQuill(quillSize, -quillAngle + 2*offSetAngle/3, imgSize/6, -imgSize/2 - 3*offSet/2);
    Feather6.growQuill(quillSize, -quillAngle + 3*offSetAngle/2, imgSize/3, -imgSize/2 + offSet);
    Feather7.growQuill(quillSize, -quillAngle + 2*offSetAngle, imgSize/2 - offSet*2, -imgSize/2 + offSet*6);

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
