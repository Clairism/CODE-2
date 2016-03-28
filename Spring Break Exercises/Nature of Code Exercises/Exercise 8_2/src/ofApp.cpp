#include "ofApp.h"

void ofApp::generate(){
    
    vector <KochLine> next;
    
    for(KochLine line : kochLines){
        ofVec2f a = line.kochA();
        ofVec2f b = line.kochB();
        ofVec2f c = line.kochC();
        ofVec2f d = line.kochD();
        ofVec2f e = line.kochE();
        
        next.push_back(KochLine(a,b));
        next.push_back(KochLine(b,c));
        next.push_back(KochLine(c,a));
        next.push_back(KochLine(d,e));
    }
    
    kochLines = next;
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    
    //lines = new ArrayList<KochLine>();
 /*
    ofPoint a, b, c;
    a.x = 0;
    a.y = 173;
    b.x = ofGetWidth();
    b.y = 173;
    c.x = ofGetWidth()/2;
    c.y = 173 + ofGetWidth()*cos(ofDegToRad(30));
    
    KochLine line1;
    line1.setup(a, b);
    line1.push_back(Lines);

    KochLine line2;
    line2.setup(b, c);
    line2.push_back(Lines);
    
    KochLine line3;
    line3.setup(c, a);
    line3.push_back(Lines);
    
    for (int i = 0; i < 5; i++) {
        generate();
    }
  */
    
    /*
    lines = new ArrayList<KochLine>();
    PVector a   = new PVector(0, 173);
    PVector b   = new PVector(width, 173);
    PVector c   = new PVector(width/2, 173+width*cos(radians(30)));
    
    // Starting with additional lines
    lines.add(new KochLine(a, b));
    lines.add(new KochLine(b, c));
    lines.add(new KochLine(c, a));
*/
    
    
    start.set(0,200);
    end.set(ofGetWidth(), 200);
//
//    star.push_back( KochLine(start,_end) );
//    
//    
//    
//    for(int i = 0; i < 5; i++){
//        generate();
//    }
    
    startLine.setup(start, end);

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    for (KochLine line : kochLines){
//        line.draw();
//    }
    startLine.draw();

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
