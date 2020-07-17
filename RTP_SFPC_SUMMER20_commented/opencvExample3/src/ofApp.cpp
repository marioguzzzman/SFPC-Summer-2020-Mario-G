#include "ofApp.h"

// TOP points 

//--------------------------------------------------------------
void ofApp::setup(){

    player.load("input.mov");
    player.play();
    player.setLoopState(OF_LOOP_NORMAL);
}

//--------------------------------------------------------------
void ofApp::update(){

    player.update();
    
    // if frame is new, then find players contour
    if (player.isFrameNew()){
        
        finder.findContours(player);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.draw(0,0);
    
    ofTranslate(player.getWidth(),0);
    
    //if we have an outline
    if (finder.size() > 0){
        ofPolyline line = finder.getPolyline(0); // get the polyline
        //line = line.getSmoothed(mouseX); // mooth the point data
        line.draw();
        
        
        //
        ofPoint top;
        for (int i = 0; i < line.size(); i++){
            if (i == 0){
                top = line[i];
            } else if (line[i].y < top.y){
                top = line[i];
            }
        }
        
        topSmoothed = 0.85 * topSmoothed + 0.15 * top; // zeno thecnique
        
        //just to draw a line, trail
        history.addVertex(topSmoothed); //adding history
        if (history.size() > 50){
            history.getVertices().erase(history.getVertices().begin());
        }
        history.draw();
        
        ofSetColor(255,0,0);
        ofDrawCircle(topSmoothed, 3);
        ofSetColor(255); // outline color
        
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
