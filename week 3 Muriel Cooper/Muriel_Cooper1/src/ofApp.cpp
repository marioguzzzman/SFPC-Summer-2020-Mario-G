#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    doSaveScreen = false;

    
    gui.setup();
    gui.add(x.setup("x", 0, -600, 600));
    gui.add(y.setup("y", 0, -600, 800));
    gui.add(z.setup("z", 0, -600, 600));
    gui.add(z2.setup("z2", 0, -600, 600));
    gui.add(z3.setup("z3", 0, -3000, 1500));
    gui.add(z4.setup("z4", 0, -800, 800));
    gui.add(scaleX.setup("ScaleX", 0, -2, 2));
    

    
    font.load("Kanit-BoldItalic.ttf", 95, true, true, true); // we are adding more parameters to create vectors
//    bool _bAntiAliased=true,
//    bool _bFullCharacterSet=false, --> true
//    bool makeContours=false, --> true
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    cout << "mouseX=" << mouseX << ", mouseY=" << mouseY << endl;
    
    ofBackground(0);
    
    //------------------ BASIC TYPOGRAPHY -------------------------
//    ofSetColor(255);
//    font.drawString("BEYOND", x, y); // how do you relate the drawString to the StrinBoundingBox
    
//    ofNoFill();
//    ofRectangle rect = font.getStringBoundingBox("BEYOND", 300, 300); //posible to scale this rectangle, how?
//    ofDrawRectangle(rect);
//    //mo funciona
//    //ofPoint myScaler(2, 2);
//    //rect.scaleFromCenter(myScaler.x, myScaler.y);
//    ofFill();
    
    //------------------ ADDING VECTORS TYPOGRAPHY -------------------------

    //------------------ EXAMPLE
//        vector < ofPath > pathsx = font.getStringAsPoints("hello"); // Returns a vector of ofPaths
//        ofTranslate(200,200);
//        for (int i = 0; i < pathsx.size(); i++){
                                                    // pathsx.size()/2 will draw half of the word "he"
                                                    // we get a loop to all the points
                                                    // it will be drawn upside down
//            pathsx[i].draw();
//        }
    
//    ofEnableDepthTest(); // Allows to test is the pixels is closer or further away from the screen  // also inhibits the giu
    // also a bug with transparency --> and the solution is to draw type with vector
//
//    cam.enableOrtho(); // something further away in z has the same size
    cam.begin();
    // can we add several cameras?
    // how do we navigate in the camera with the code?
//        ofDrawAxis(200); // x , y are inverted, 100. 100. instead of going down, go up
    //
    
    
    // shorter notation is also possible
    ofColor layer3(109,122,138);
    ofColor layer2(197,206,213);
    
    ofColor layer1(255,255,255);
    
//    ofColor layer3(109,122,138);
//    ofColor layer2(197,206,213);
//    ofColor layer1(255,255,255);
    
    // or even shorter
//    ofSetColor( ofColor(0, 0, ofRandom( 128, 255 ) );
    // -- MURIEL
    int murielx = 544;
    int muriely = 93;
    int murielz = 397;
    
    // -- ALL LAYERS
    int rotateZleft = 90;
    int rotateYleft = -180;
    
    int rotateZright = -450;
    int rotateYright = -180;
    
    // ---- LAYER 1
    int depth1layer = z;
    int scale1layer = 1;
    int x1layerBeyond = -258;
    int y1layerBeyond = -300;
    int x1layerWindows = -304;
    int y1layerWindows = -168;
    
    // ---- LAYER 2
    int depth2layer = depth1layer + 165;
    int scale2layer = 1.24;
    int x2layerBeyond = -263;
    int y2layerBeyond = -110;
    int x2layerWindows = -301;
    int y2layerWindows = -300;
    
    // ---- LAYER 3
    int depth3layer = depth2layer * 2;
    int scale3layerBeyond = 1.3;
    int scale3layerWindows = 1.1;

    int x3layerBeyond = -262;
    int y3layerBeyond = -194;
    int x3layerWindows = -314;
    int y3layerWindows = -92;
    
    

    
    //------------------ THIRD LAYER -------------------------
//


    //    //TOP word
    ofSetColor(layer3);
    ofPushMatrix();
    ofRotateYDeg(180);
    ofScale(1.3,-1.3); // (1,-1) This flips the Y axis and solves the problem created by the for loop
    ofTranslate(x3layerBeyond,y3layerBeyond, depth3layer);
    vector < ofPath > paths10 = font.getStringAsPoints("BEYOND");
    for (int i = 0; i  < paths10.size(); i++){
        paths10[i].draw();
    }
    ofPopMatrix();


    //    //BOTTON word
    //    ofSetColor(255);
    ofPushMatrix();
    ofRotateXDeg(536);
    ofScale(1.3,-1.3);
    ofTranslate(x3layerBeyond,y3layerBeyond, depth3layer); // same as above but Y inverted
    vector < ofPath > paths11 = font.getStringAsPoints("BEYOND");
    for (int i = 0; i  < paths11.size(); i++){
        paths11[i].draw();
    }
    ofPopMatrix();

    //    //LEFT word
    //    ofSetColor(255);
    ofPushMatrix();
    ofRotateZDeg(rotateZleft);
    ofRotateYDeg(rotateYleft);
    ofScale(1.1,-1.1);
    ofTranslate(x3layerWindows,y3layerWindows, depth3layer); // same as above but Y inverted
    vector < ofPath > paths12 = font.getStringAsPoints("WINDOWS");
    for (int i = 0; i  < paths12.size(); i++){
        paths12[i].draw();
    }
    ofPopMatrix();

    //    //RIGht word
    //    ofSetColor(255);
    ofPushMatrix();
    ofRotateZDeg(rotateZright);
    ofRotateYDeg(rotateYright);
    ofScale(1.1,-1.1);
    ofTranslate(x3layerWindows,y3layerWindows, depth3layer); // same as above but Y inverted
    vector < ofPath > paths13 = font.getStringAsPoints("WINDOWS");
    for (int i = 0; i  < paths13.size(); i++){
        paths13[i].draw();
    }
    ofPopMatrix();
    
    //------------------ SECOND LAYER -------------------------
    
   
    //    //TOP word
    ofSetColor(layer2);
    ofPushMatrix();
    ofRotateYDeg(180);
    ofScale(1,-1); // (1,-1) This flips the Y axis and solves the problem created by the for loop
    ofTranslate(x2layerWindows,y2layerWindows, depth2layer);
    vector < ofPath > paths6 = font.getStringAsPoints("WINDOWS");
    for (int i = 0; i  < paths6.size(); i++){
        paths6[i].draw();
    }
    ofPopMatrix();
    
    
    //    //BOTTON word
    //    ofSetColor(255);
    ofPushMatrix();
    ofRotateXDeg(536);
    ofScale(1,-1);
    ofTranslate(x2layerWindows,y2layerWindows, depth2layer); // same as above but Y inverted
    vector < ofPath > paths7 = font.getStringAsPoints("WINDOWS");
    for (int i = 0; i  < paths7.size(); i++){
        paths7[i].draw();
    }
    ofPopMatrix();
    
    
    //    //LEFT word
    //    ofSetColor(255);
    ofPushMatrix();
    ofRotateZDeg(rotateZleft);
    ofRotateYDeg(rotateYleft);
    ofScale(1.24,-1.24);
    ofTranslate(x2layerBeyond,y2layerBeyond, depth2layer); // same as above but Y inverted
    vector < ofPath > paths8 = font.getStringAsPoints("BEYOND");
    for (int i = 0; i  < paths8.size(); i++){
        paths8[i].draw();
    }
    ofPopMatrix();
    
    
    //    //RIGht word
    //    ofSetColor(255);
    ofPushMatrix();
    ofRotateZDeg(rotateZright);
    ofRotateYDeg(rotateYright);
    ofScale(1.24,-1.24);
    ofTranslate(x2layerBeyond,y2layerBeyond, depth2layer); // same as above but Y inverted
    vector < ofPath > paths9 = font.getStringAsPoints("BEYOND");
    for (int i = 0; i  < paths9.size(); i++){
        paths9[i].draw();
    }
    ofPopMatrix();
    
    
//------------------ FIRST LAYER -------------------------
    

        //    //TOP word
        ofSetColor(layer1);
        ofPushMatrix();
            ofRotateYDeg(180);
                ofScale(1,-1); // (1,-1) This flips the Y axis and solves the problem created by the for loop
                ofTranslate(x1layerBeyond,y1layerBeyond, depth1layer);
                vector < ofPath > paths1 = font.getStringAsPoints("BEYOND");
                for (int i = 0; i  < paths1.size(); i++){
                    paths1[i].draw();
                }
        ofPopMatrix();
    
    
    //    //BOTTON word
    //    ofSetColor(255);
        ofPushMatrix();
            ofRotateXDeg(536);
                ofScale(1,-1);
                ofTranslate(x1layerBeyond,y1layerBeyond, depth1layer); // same as above but Y inverted
                vector < ofPath > paths = font.getStringAsPoints("BEYOND");
                for (int i = 0; i  < paths.size(); i++){
                    paths[i].draw();
                }
        ofPopMatrix();
    
    //    //LEFT word
    //    ofSetColor(255);
    ofPushMatrix();
        ofRotateZDeg(rotateZleft);
        ofRotateYDeg(rotateYleft);
            ofScale(1,-1);
            ofTranslate(x1layerWindows,y1layerWindows, depth1layer); // same as above but Y inverted
            vector < ofPath > paths3 = font.getStringAsPoints("WINDOWS");
            for (int i = 0; i  < paths3.size(); i++){
                paths3[i].draw();
            }
    ofPopMatrix();
    
    //    //RIGht word
    //    ofSetColor(255);
    ofPushMatrix();
        ofRotateZDeg(rotateZright);
            ofRotateYDeg(rotateYright);
                ofScale(1,-1);
                ofTranslate(x1layerWindows,y1layerWindows, depth1layer); // same as above but Y inverted
                vector < ofPath > paths4 = font.getStringAsPoints("WINDOWS");
                for (int i = 0; i  < paths4.size(); i++){
                    paths4[i].draw();
                }
    ofPopMatrix();
    
    //    //MURIEL
    //    ofSetColor(255);
    ofPushMatrix();
        ofRotateXDeg(-228); //-228
        ofRotateYDeg(-282); //-282
        ofRotateZDeg(224); //224

            ofScale(1,-1);
            ofTranslate(murielx, muriely, murielz + depth1layer); // same as above but Y inverted 544, 93, 397
    
    
            vector < ofPath > paths5 = font.getStringAsPoints("MURIEL COOPER");
            for (int i = 0; i  < paths5.size(); i++){
                paths5[i].draw();
            }
    ofPopMatrix();
    
    

//    //Botton word
//    ofSetColor(255);
//    ofPushMatrix();
//    ofRotateXDeg(-180);
//    ofScale(1,1);
//    ofTranslate(0,0);
//    vector < ofPath > paths3 = font.getStringAsPoints("WINDOWS");
//    for (int i = 0; i  < paths3.size(); i++){
//        paths3[i].draw();
//    }
//    ofPopMatrix();
//
//    ofSetColor(255, 0,0);
//    ofPushMatrix();
//    ofRotateYDeg(90);
//    ofScale(1,-1);
//    vector < ofPath > paths2 = font.getStringAsPoints("world");
//    for (int i = 0; i  < paths2.size(); i++){
//        paths2[i].draw();
//    }
//    ofPopMatrix();
//
//
    cam.end();
    
   
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
