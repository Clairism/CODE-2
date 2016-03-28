#include "ofApp.h"

/*
void generate() {
    
    vector <KochLine> next;
    
    for (KochLine l : Lines) {
        // Calculate 5 koch ofVec2fs (done for us by the line object)
        ofVec2f a = l.kochA();
        ofVec2f b = l.kochB();
        ofVec2f c = l.kochC();
        ofVec2f d = l.kochD();
        ofVec2f e = l.kochE();
        // Make line segments between all the ofVec2fs and add them
        next.push_back(KochLine(a, b));
        next.push_back(KochLine(b, c));
        next.push_back(KochLine(c, d));
        next.push_back(KochLine(d, e));
        
    }
    
    Lines = next;
};
 */

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
//    ofSetLineWidth(5);

    
    start.set(0, 150);
    end.set(ofGetWidth(), 150);
    
    KochLine startLine(start, end);

    Lines.push_back(startLine); //add startline into the array Lines


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
//    if (key == 'p'){
//        generate();
//    }
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
