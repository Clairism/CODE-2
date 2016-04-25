#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    w = ofGetWidth();
//    h = ofGetHeight();
    /*
    cat.load("cat.jpg");
    
    w = cat.getWidth();
    h = cat.getHeight();
     */
    ofBackground(0, 0, 0);
    source.load("cat.jpg");
    
    result.clone(source);
    
}

//--------------------------------------------------------------
void ofApp::update(){
//    unsigned char *data = new unsigned char[w * h * 4];
    //the "*" is a pointer; we will worry about this later

/*
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
*/
    
    
    int angle = mouseX;
    int w = source.getWidth();
    int h = source.getHeight();
    int cx = w/2; //center
    int cy = h/2;
    int bpp = 3;
    
    //make result background black by setting memory to 0
    memset(result.getPixels(), 0, bpp*w*h);
    
    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {
            
            // xx range between -cx..0..cx instead of 0..w
            // so we're changing the pivot point from topleft to center
            int xx = x - cx;
            int yy = y - cy;
            
            //distance from pixel to center of image
            float r = sqrt(xx*xx+yy*yy);
            
            //current angle of pixel + rotation angle
            float phi = atan2(yy,xx) + HALF_PI + ofDegToRad(angle);
            
            //calculate new pixel position
            xx = r*sin(phi) + cx;
            yy = r*cos(phi) + cy;
            
            // if out of bounds leave background black
            if (xx<0 || yy<0 || xx>w || yy>h) continue;
            
            //calculate position of pixel in array
//            unsigned char *to = result.getPixels() + bpp*y*w + bpp*x;
//            unsigned char *from = result.getPixels() + bpp*yy*w + bpp*xx;
            unsigned char *to = result.getPixels();
            unsigned char *from = result.getPixels();

            ofPixels p = source.getPixels();
            memcpy(to, from, bpp);
            
        }
    }
    
    result.update();
     
    
//    ofPixels p = source.getPixels();
//    p.allocate(100, 100, OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofBackground(255, 255, 255);
//    ofSetColor( 255, 255, 255 );
    
    result.draw( 0, 0, 700, 500);
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
