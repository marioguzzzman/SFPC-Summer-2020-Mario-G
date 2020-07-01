 #include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowShape(800, 800);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
//    for (int i = 0; i < 50; i++){
//
//        // we love #s between 0-1
//
//        float pct = ofMap(i, 0, 49, 0, 1);
//        pct = powf(pct, mouseX * 0.01);
//        float x = ofMap(pct, 0, 1, 50, 750); // this creates a linear spacing of 50 circles // this creates NON-LINEAR DIVISION OF SPACE
//        ofDrawCircle(x,400, 3);
//
//    } 
    
    float w = ofGetWidth()/30.0; // this just gives us the size of the square
    float h = ofGetWidth()/30.0;
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; j++){

            //NON - LINEAR DIVISION OF SPACE
            float xPct = ofMap(i, 0, 30, 0, 1); // converted into a number between 0 and 1
            xPct = powf(xPct, mouseX * 0.01); // but then is more interesting if you add it to a fractional power
            
            float xPct2 = ofMap(i+1, 0, 30, 0, 1); // this is the second perfent, the amount of change in the square
            xPct2 = powf(xPct2, mouseX * 0.01);
            
            
            float x = ofMap(xPct, 0, 1, 0, ofGetWidth());
            float x2 = ofMap(xPct2, 0, 1, 0, ofGetWidth());
            
            float y = ofMap(j, 0, 30, 0, ofGetWidth());
            
            if ((j + i) % 2 == 0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            ofDrawRectangle(x,y, x2-x, h);
        }
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
