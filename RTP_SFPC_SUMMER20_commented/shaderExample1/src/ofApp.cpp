#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    shader.load("", "shader.frag"); // load the shader
}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetFrameNum() % 60) shader.load("", "shader.frag"); // every 60 frames, once every second, reload the shared. then you can alter and you see it. Also incude the shader file, so the porgram compules.
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // you mainly draw in the shader.frag instead of in draw

    ofSetColor(255);
    
    shader.begin();
    
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("mouse", mouseX, mouseY);
//
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight()); // this draws a rectangle that is the size of the window.
    //ofDrawCircle(mouseX,mouseY,100);
    shader.end();
    
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
