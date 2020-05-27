#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    attempt = 0;
    doSaveScreen = false;
    
    gui.setup();
    gui.add(rectSize.setup("rect size", 50, 10, 200));
    gui.add(mapx1.setup("mapx1", 237, 10, 1000));
    gui.add(mapx2.setup("mapx2", 688, 10, 1000));
    gui.add(mapy1.setup("mapy1", 123, 10, 1000));
    gui.add(mapy2.setup("mapy2", 401, 10, 1000));
//    gui.add(overRect.setup("overRect", 87, 0, 100));
//    gui.add(overlapX.setup("overlapX", 1, 0, 255));
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //    ofBackground(0);
    //ofBackground(237,25,65); //44 Trapèzes (144 Trapeziums) - 1974 - computer graphic, open series, 16 variations
    ofBackground(220,119,91); // Vera Molnár
    ofSetColor(226,207,208, 90);
    ofNoFill();
    ofSetLineWidth(0.5);
    
    ofSeedRandom(mouseX*1000); // hack to achieve seed`s big number
//    ofSeedRandom(87*1000); // number MOLNAR

   // float offset = mouseY; // variation on lines
//    float offset = ofMap(mouseY, 0, 800, 0, 50); // variation on lines
    float offset = ofMap(144, 0, 800, 0, 50); // variation on lines MOLNAR


    cout << "mouseX=" << mouseX << ", mouseY=" << mouseY << endl; //print X and Y
    
    switch (attempt) {
        case 0:
            
//            caseName = "0";
//            ofDrawBitmapString(caseName, ofGetWidth()-100,ofGetHeight()-100);
            
            for (int col = 0 ; col < 9; col++) {
                for (int row = 0; row < 6; row++){
                    
                    float x = ofMap(col, 0, 8, mapx1, mapx2);
                    float y = ofMap(row, 0, 5, mapy1, mapy2);
                    
//                    float x = ofMap(i, 0, 8, 252, 712);
//                    float y = ofMap(j, 0, 5, 123, 401);
//                    rectSize = 50;
                    
//                    ofDrawCircle(x,y,2); // visualize grid

                    int qlines = col * 2;

                    if (col < 1 || col > 7){
                        qlines = 1;
                    } else if (col > 6 ){
                        qlines = 2;
                    } else if (col > 5){
                        qlines = 8;
                    } else if (col > 4){ // column 5
                        qlines = 30;
                    }else if (col > 3){
                        qlines = 15;
                    }
                    
                    for (int k = 0;k < qlines; k++){

                    ofPushMatrix();
                    ofTranslate(x, y);
                    //square shape
                    ofBeginShape();
                    ofVertex(ofRandom(-offset,offset) , ofRandom(-offset,offset));
                    ofVertex(rectSize + ofRandom(-offset,offset), ofRandom(-offset,offset));
                    ofVertex(rectSize + ofRandom(-offset,offset), rectSize + ofRandom(-offset,offset));
                    ofVertex(ofRandom(-offset,offset), rectSize + ofRandom(-offset,offset));
                    ofEndShape(true);
                    
                    ofPopMatrix();
                        
                    }
                }
                
               
            }
            
 
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
