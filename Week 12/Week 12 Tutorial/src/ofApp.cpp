#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    w = ofGetWidth();
//    h = ofGetHeight();
    
    cat.load("cat.jpg");
    
    w = cat.getWidth();
    h = cat.getHeight();
    
}

//--------------------------------------------------------------
void ofApp::update(){
//    unsigned char *data = new unsigned char[w * h * 4];
    //the "*" is a pointer; we will worry about this later


    unsigned char* data = cat.getPixels();
    
    int bpp = cat.getPixels().getBitsPerPixel();
    
    //calculate the num of pixels
    int comp = bpp / 8;

    for (int y = 0; y < h; y ++) {
        for (int x = 0; x < w; x ++) {
            
            cat.getColor(x, y);

            int red = ofMap( sin(ofGetElapsedTimef()), -1, 1, 0, 255 );
            int green = ofMap( cos(ofGetElapsedTimef()), -1, 1, 0, 255 );
            int blue = ofMap( tan(ofGetElapsedTimef()), -1, 1, 0, 255 );
            int alpha = 255;
            
            int index = comp * ( x + w * y );
//            cout << "indexs: " << index << endl;
            
//            data[ index ] = red;
//            data[ index + 1 ] = green;
//            data[ index + 2 ] = blue;
//            data[ index + 3 ] = alpha;
            
            
        }
    }
    
//    cat.setFromPixels(data, w, h, OF_IMAGE_COLOR_ALPHA);
//    delete[] data;

    cat.update();

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255, 255, 255);
    ofSetColor( 255, 255, 255 );
    
    cat.draw( 0, 0 );
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
