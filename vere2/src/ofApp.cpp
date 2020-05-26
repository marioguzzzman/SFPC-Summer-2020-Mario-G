#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    attempt = 0;
    doSaveScreen = false;
    
    gui.setup();
    gui.add(rectSize.setup("rect size", 70, 10, 200));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //    ofBackground(0);
    ofBackground(237,25,65); //44 Trapèzes (144 Trapeziums) - 1974 - computer graphic, open series, 16 variations
    ofSetColor(255);
    ofNoFill();
    
    ofSeedRandom(mouseX*1000); // hack to achieve seed`s big number
    float offset = mouseY; // variation on lines
    
    
    switch (attempt) {
        case 0:
            ofDrawCircle(400, 400, rectSize);

            ofDrawRectangle(400, 400, rectSize, rectSize);
       
            break;
            
        case 1:
            ofDrawRectangle(200, 200, rectSize, rectSize);

            ofDrawRectangle(600, 600, rectSize, rectSize);

            break;
    }
    
    //write something to hide or show the guibar
    gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
            
        case 57358: // right arrow
            attempt++;
            break;
        case 57356: // left arrow
            attempt--;
            break;
    }
    
    if(key == 'x'){
        doSaveScreen = true;
        
        if(doSaveScreen){
            ofSaveScreen(ofToString(ofGetFrameNum())+".png");
            doSaveScreen = false;
            
            //        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
            //        img.save("screenshot.png");
        }
        
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
