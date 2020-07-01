#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowShape(800,800);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);

    //TECHNIQUE TO DISTORT
    //ask questions about the elements on the grid.
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; j++){
            
            float x = ofMap(i, 0, 29, 50, 750);
            float y = ofMap(j, 0, 29, 50, 750);
            
            float distance = ofDist(x,y,mouseX, mouseY); // distance 
            float pct = ofMap(distance, 0, 200, 1,0, true); // true, clamps the value, between 1 and 0
            // with in 200 pixels of the mouse
            
            ofPoint circle(x,y);
            ofPoint mouse(mouseX, mouseY);
            ofPoint diff = circle - mouse; // line that connects two points
            diff.normalize();              // manage the length to 0 and 1
            circle = circle + diff * pct * 50; // pushes the circles
            
            
            ofDrawCircle(circle.x,circle.y,5 + 8 * pct); // based on the distance from the mouse change
            
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
