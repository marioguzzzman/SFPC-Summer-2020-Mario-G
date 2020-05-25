#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    attempt = 0; // You can change this to whatever default you want
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofDrawCircle();
    //ofDrawRectangle();
    
    //    ofBackground(0);
    ofBackground(237,25,65); //44 Trapèzes (144 Trapeziums) - 1974 - computer graphic, open series, 16 variations
    ofSetColor(255);
    ofNoFill();
    
    ofSeedRandom(mouseX*1000); // hack to achieve seed`s big number
    float offset = mouseY; // variation on lines
    
    int intuition = ofRandom(-offset,offset);
    
    float rectSize;
    
    int v1 ;
    int v2 ;
    int displaceX;
    int displaceY;

    //     --------------------------------------------------------------
    
    switch (attempt) {
        case 1:
            
            ofBackground(0);
            ofSetColor(255);
            
            ofNoFill();
            ofBeginShape();
            ofVertex(200 + ofRandom(-offset,offset),200);
            ofVertex(600 + ofRandom(-offset,offset),200);
            ofVertex(600 + ofRandom(-offset,offset),600);
            ofVertex(200 + ofRandom(-offset,offset),600);
            ofEndShape(true);
            
            break;
            
            //     --------------------------------------------------------------
            
        case 2:
            
            ofBackground(255, 0, 0);
            ofSetColor(255);
            
            ofNoFill();
            
            ofSeedRandom(mouseX);
            
            for (int i =0; i< 800; i++){
                for (int j =0; j< 800; j++){
                    ofDrawCircle(i, 400 + ofRandom(-100, 100), 2);
                }
            }
            
            ofBeginShape();
            ofVertex(200 + ofRandom(-offset,offset),200);
            ofVertex(600 + ofRandom(-offset,offset),200);
            ofVertex(600 + ofRandom(-offset,offset),600);
            ofVertex(200 + ofRandom(-offset,offset),600);
            ofEndShape(true);
            
            ofSetColor(0);
            ofBeginShape();
            ofVertex(200 + intuition,200);
            ofVertex(600 + intuition,200);
            ofVertex(600 + intuition,600);
            ofVertex(200 + intuition,600);
            ofEndShape(true);
            break;
            
            //     --------------------------------------------------------------
        case 3:
            
            for (int i = 0; i < 6; i++){
                for (int j = 0; j < 6; j++){
                    float x = ofMap(i, 0, 5, 50, 100);
                    float y = ofMap(j, 0, 5, 50, 100);
                    
                    ofPushMatrix();
                    ofTranslate(x, y);
                    ofRotateDeg( ofRandom(0,360));
                    if (ofNoise(i*0.1, j*0.1) < .9){
                        //                        ofDrawLine(-15, 0, 0+15, 0);
                        
                        ofDrawCircle(i + i*100, 400 + ofRandom(-100, 100), 2);
                        ofBeginShape();
                        ofVertex(200 + ofRandom(-offset,offset),200);
                        ofVertex(600 + ofRandom(-offset,offset),200);
                        ofVertex(600 + ofRandom(-offset,offset),600);
                        ofVertex(200 + ofRandom(-offset,offset),600);
                        ofEndShape(true);
                        
                    }
                    ofPopMatrix();
                    //ofDrawCircle(x,y,5);
                }
            }
            
            //            ofBeginShape();
            //            ofVertex(200 + ofRandom(-offset,offset),200);
            //            ofVertex(600 + ofRandom(-offset,offset),200);
            //            ofVertex(600 + ofRandom(-offset,offset),600);
            //            ofVertex(200 + ofRandom(-offset,offset),600);
            //            ofEndShape(true);
            break;
            
            //     --------------------------------------------------------------
            
            
        case 4:
       
            v1 = 50;
            v2 = 100;
            
            for (int i = 0; i < 6; i++){
                for (int j = 0; j < 6; j++){
                    float x = ofMap(i, 0, 5, 150, 650);//grid
                    float y = ofMap(j, 0, 5, 150, 650);//grid
                    
                    //                    ofPushMatrix();
                    //                    ofTranslate(x, y);
                    //                    ofRotateDeg( ofRandom(0,360)); //rotatin lines
                    //                    if (ofNoise(i*0.1, j*0.1) < .9){
                    
                    ofDrawLine(-15, 0, 0+15, 0);
                    ofDrawCircle(x,y,2);
                    
                    //drawn all shapes in the same spot
//                    ofBeginShape();
//                    ofVertex(200 + ofRandom(-offset,offset),200+ ofRandom(-offset,offset));
//                    ofVertex(600 + ofRandom(-offset,offset),200+ ofRandom(-offset,offset));
//                    ofVertex(600 + ofRandom(-offset,offset),600+ ofRandom(-offset,offset));
//                    ofVertex(200 + ofRandom(-offset,offset),600+ ofRandom(-offset,offset));
//                    ofEndShape(true);
                    
                    //Entangled mesh
                    ofBeginShape();
                    ofVertex(x + ofRandom(-offset,offset),x+ ofRandom(-offset,offset));
                    ofVertex(y + ofRandom(-offset,offset),x+ ofRandom(-offset,offset));
                    ofVertex(y + ofRandom(-offset,offset),y+ ofRandom(-offset,offset));
                    ofVertex(x + ofRandom(-offset,offset),y+ ofRandom(-offset,offset));
                    ofEndShape(true);
                }
                    //                    }
                    //                    ofPopMatrix();
            }
            
            //single figure
            ofBeginShape();
            ofVertex(v1 + ofRandom(-offset,offset),v1+ ofRandom(-offset,offset));
            ofVertex(v2 + ofRandom(-offset,offset),v1+ ofRandom(-offset,offset));
            ofVertex(v2 + ofRandom(-offset,offset),v2+ ofRandom(-offset,offset));
            ofVertex(v1 + ofRandom(-offset,offset),v2+ ofRandom(-offset,offset));
            ofEndShape(true);
            
            break;
            
            //     --------------------------------------------------------------

        case 5:
            
            break;
            
    //     --------------------------------------------------------------

            
        case 0:

            ofSeedRandom(mouseX*1000); // hack to achieve seed`s big number
//            ofSeedRandom(0); // hack to achieve seed`s big number

            float offset = ofMap(mouseY, 0, 800, 0, 50); // variation on lines
            
            for (int i = 0; i < 6; i++){
                for (int j = 0; j < 6; j++){
                    float x = ofMap(i, 0, 5, 100, 630);//grid
                    float y = ofMap(j, 0, 5, 100, 630);//grid
                    
//                    ofDrawCircle(x,y,2); // visualize grid
                    
                     rectSize = 70;
                    
                    //drawn all shapes in the same spot
//                    ofBeginShape();
//                    ofVertex(v1 + ofRandom(-offset,offset),v1+ ofRandom(-offset,offset));
//                    ofVertex(v2 + ofRandom(-offset,offset),v1+ ofRandom(-offset,offset));
//                    ofVertex(v2 + ofRandom(-offset,offset),v2+ ofRandom(-offset,offset));
//                    ofVertex(v1 + ofRandom(-offset,offset),v2+ ofRandom(-offset,offset));
//                    ofEndShape(true);
                    
                    // TRANSLATE
//                   ofTranslate(x,y) ads x,y so we don’t add it again
                    ofPushMatrix();
                    ofTranslate(x, y); // copy of map
                    
                    ofBeginShape();
                    ofVertex(ofRandom(-offset,offset) , ofRandom(-offset,offset));
                    ofVertex(rectSize + ofRandom(-offset,offset), ofRandom(-offset,offset));
                    ofVertex(rectSize + ofRandom(-offset,offset), rectSize + ofRandom(-offset,offset));
                    ofVertex(ofRandom(-offset,offset), rectSize + ofRandom(-offset,offset));
                    ofEndShape(true);
                        
                    ofPopMatrix();

                    // relative
//                    ofBeginShape();
//                    ofVertex(x + ofRandom(-offset,offset) , y + ofRandom(-offset,offset));
//                    ofVertex(x + rectSize + ofRandom(-offset,offset), y + ofRandom(-offset,offset));
//                    ofVertex(x + rectSize + ofRandom(-offset,offset), y + rectSize + ofRandom(-offset,offset));
//                    ofVertex(x + ofRandom(-offset,offset), y + rectSize + ofRandom(-offset,offset));
//                    ofEndShape(true);
                  
                }
            }
            
            break;
            
    }
    
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
