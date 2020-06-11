#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   doSaveScreen = false;
    
    gui.setup();
    gui.add(cosA.setup("cosAnglex", 3, 1, 5));
    gui.add(sinA.setup("sinAnglex", 3.7, 1, 5));
    gui.add(radius.setup("radius", 115, 10, 150));
    gui.add(radiusCicle.setup("radiusCicle", 30, 10, 150));
    gui.add(phaseDistance.setup("phaseDistance", 0, 0, 150));
    gui.add(xtest.setup("x", 400, 0, 800));
    gui.add(ytest.setup("y", 400, 0, 800));



    
    
    ofSetCircleResolution(6);  // hack to make hexagons

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofNoFill();
    
    float xorig = 400;
    float yorig = 400;
    
    
    ofSetColor(255);
    for (int i = 0; i < 6; i++){
        float angle = ofGetElapsedTimef();
        float phaseOffSet = i * sin(angle);
        
        float x = xorig + radius * cos(angle * cosA + phaseOffSet);
        float y = yorig + radius * sin(angle * sinA + phaseOffSet);
        
//        ofDrawCircle(x + i * phaseDistance, y + i * phaseDistance , x * sin(angle) * .3);
        
            ofDrawCircle(x, y , x * sin(angle) * .3);
            ofDrawCircle(x+xtest, y +ytest , x * sin(angle) * .3);



        
//        trail.addVertex(x,y);
//        if (trail.size() > 800){
//            trail.getVertices().erase(trail.getVertices().begin());
//        }
//        trail.draw();
    }
    
//    ofSetColor(255, 0, 0);
//    for (int i = 0; i < 6; i++){
//        float angle = ofGetElapsedTimef();
//        float x = xorig + radius * sin(angle * cosA);
//        float y = yorig + radius * cos(angle * sinA);
//
//        ofDrawCircle(x + i * phaseDistance, y + i * phaseDistance , radiusCicle);
//
//        trail.addVertex(x,y);
//        if (trail.size() > 600){
//            trail.getVertices().erase(trail.getVertices().begin());
//        }
//        trail.draw();
//    }
    
   
    
   
    
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
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
