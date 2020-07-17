#include "ofApp.h"

//store a emmory
//picels at the top are old pixels
//picels at the botton are pixels happening now

//https://www.dictionaryofobscuresorrows.com/page/4
//Kinsugi
//n. a kind of melancholic trance in which you become completely absorbed in vivid sensory details—raindrops skittering down a window, tall trees leaning in the wind, clouds of cream swirling in your coffee—briefly soaking in the experience of being alive, an act that is done purely for its own sake.

//--------------------------------------------------------------
void ofApp::setup(){
//GUI
    gui.setup();
    gui.add(x.setup("x", 0, 0, ofGetWindowWidth()));
    gui.add(y.setup("y", 0, 0, ofGetWindowHeight()));
    gui.add(z.setup("z", 0, 0, 255));
    
//CAMERA
    grabber.listDevices();
    grabber.setDeviceID(1);
    
    grabber.setup(640, 480);

//IMAGE
    original.load("test.jpg");
    original.resize(ofGetWindowWidth(), ofGetWindowHeight());
    original.setImageType(OF_IMAGE_COLOR);
    img.allocate(original.getWidth(), original.getHeight(), OF_IMAGE_COLOR);
    
    
//TEXT
//    font.load("RobotoSlab-Light.ttf", 95, true, true, true); // we are adding more parameters to create vectors
    font.load("Kanit-BoldItalic.ttf", 95, true, true, true); // we are adding more parameters to create vectors
//    //    bool _bAntiAliased=true,
//    //    bool _bFull:-1: Skipping duplicate build file in Compile Sources build phase: /Users/marioguzman/Desktop/school_SFPC/of_v0.11.0_osx_release/libs/openFrameworks/app/ofBaseApp.cpp (in target 'openFrameworks')CharacterSet=false, --> true
//    //    bool makeContours=false, --> true
//
    
    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA);
    
    ofSeedRandom(0);

    string text = "A glitch is a singular dysfunctional event that allows insight beyond the customary, omnipresent, and alien computer aesthetics";
}

//--------------------------------------------------------------
void ofApp::update(){
//    original.update();
    
//    grabber.update();

// --------FBO
    
    fbo.begin();
    
    ofClear(255,255,255,0);
    
// ------- RUTT ETRA2
//        ofClear(0,0,0,0);

//        cam.begin(); // camera need to be flipped
//        ofSetColor(255, 0, 0);
//        cam.enableOrtho();// what was this for? you need to rotate tu see
//
//        for (int y = 0; y < grabber.getHeight(); y+=30){
//            ofPolyline line;
//            for (int x = 0; x < grabber.getWidth(); x++){
//                float brightness = grabber.getPixels().getColor(x,y).getBrightness();
//                line.addVertex(x - grabber.getWidth()/2, (grabber.getHeight()-y-1) - grabber.getHeight()/2, ofMap(brightness, 0, 255, -mouseX, mouseX)); //restar grabber to change the center of the camera
//                // too add distorcion we add the brigthnes to z
//                // adding the -1 to y to flip the image
//                // amunt of offset controlled by mouse
//            }
//            line = line.getSmoothed(10);
//            line.draw();
//        }
//        cam.end();

// ------- IMAGE
    //    ofSetColor(255);
    //    original.draw(0,0); // DRAW normal image

// ------- IMAGE GLICHED
    //    image glitch
    //    ofEnableAlphaBlending();
    //    ofSetColor(255,255,255,50);
    //    newImage.draw(0,0); // image glitch
    //    ofDisableAlphaBlending();
    
 
// -------- TEXT WITH BLENDING

        ofEnableAlphaBlending();
    
            ofSetColor(0);
        // -------- SIMPLE TEXT
    
        //    ofSetColor(0);
        //    drawWarpedText2("glitch", mouseX - 50, mouseY - 50, 300, 300);

            ofSeedRandom(mouseX);
    
            int size = 90;
            for (int i = 0; i < 5; i++){
                drawWarpedText2("kinsugi", mouseX, mouseY, 500, 500/3);

//                drawWarpedText2("kinsugi", ofRandom(0, mouseX), ofRandom(0, mouseY), 300, 100);
//                drawWarpedText2("ambido", ofGetWindowWidth()/2, ofGetWindowHeight()/2, 100, 75);
//                drawWarpedText2("kinsugi", ofGetWindowWidth()-x, ofGetWindowHeight()-y, size, size/3);
                
//                x = 450
//                y = 320
            }

        ofDisableAlphaBlending();

    
// -------- GLICTH IMAGE CODE
    
//        ofBuffer buffer; // space in memory ram
//        ofSaveImage(original.getPixels(), buffer, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_BEST);
//
//        ofSeedRandom(0);
//
//        //mouseX where to skip
//        int whereToSkip = ofMap(mouseX, 0, ofGetWidth(), 0, buffer.size(), true);
//        int left = buffer.size() - whereToSkip;
//
//        //mouseY where to skip
//        int howMuchToSkip = ofMap(mouseY, 0, ofGetHeight(), 0, left*0.5, true);
//
//        ofBuffer buffer2;
//
//        //sends data from one buffer to anotherone
//
//        // if i am in between the place I want to skip to
//        for (int i = 0; i < buffer.size(); i++){
//            if (i < whereToSkip ||
//                i > (whereToSkip+howMuchToSkip)){
//                buffer2.append(buffer.getData() + i, 1);
//            } else { // or append  random data
//                char * data = new char[1];
//                data[0] = ofRandom(0,255);
//                buffer2.append(data, 1);
//                delete data;
//            }
//        }
//        newImage.load(buffer2);

// --------FBO

    fbo.end(); // ---------------------------
    
    
    
    //current image pixels from FBO
    ofPixels curentImagePixels;
    fbo.readToPixels(curentImagePixels);
    
    // Store images
        ofImage imgTemp;
        images.push_back(imgTemp);
        images.back().setUseTexture(false); // set to false if you only want to store the pixel data instead of showing the images
        images.back().setFromPixels(curentImagePixels); // allocate the images
        
        if (images.size() > 80){ // how many to store
            images.erase(images.begin());
        }
    
// GLITCH CODE 1 SLIT SCANN
//     composite them in a single image
    if (images.size() > 0){
        for (int y = 0; y < fbo.getHeight(); y++){ // vetically
            int whichImage = ofMap(y, 0, fbo.getHeight(), 0, images.size());
            for (int x = 0; x < fbo.getWidth(); x++){
                ofColor color = images[whichImage].getColor(x,y); // copy pixels across
                img.setColor(x, y, color);
            }
        }
    }
    
//    img.update(); // slit scan
    
    
// --------  GLITCH CODE 2 noise version
    
        float time = ofGetElapsedTimef(); //grab time

        if (images.size() > 1){
            for (int y = 0; y < fbo.getHeight(); y++){
                //ofMap(y, 0, grabber.getHeight(), 0, images.size());
                for (int x = 0; x < fbo.getWidth(); x++){
    
                    int whichImage = ofMap(ofNoise(x*0.01,
                                                   y*0.01, time), 0, 1, 0, images.size()-1);
    
    
                    ofColor color = images[whichImage].getColor(x,y);
                    img.setColor(x, y, color);
                }
            }
        }
    
    
    img.update(); // --------> IMAGE TO DISPLAY
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofBackground(0);
    
    //------------------ BASIC TYPOGRAPHY -------------------------
//        ofSetColor(255);
//        font.drawString("ABC", ofGetWindowWidth()/2, ofGetWindowHeight()/2); // how do you relate the drawString to the StrinBoundingBox
//
//        ofNoFill();
//        ofRectangle rect = font.getStringBoundingBox("ABC",ofGetWindowWidth()/2, ofGetWindowHeight()/2); //posible to scale this rectangle, how?
//        ofDrawRectangle(rect);
//        //mo funciona
//        //ofPoint myScaler(2, 2);
//        //rect.scaleFromCenter(myScaler.x, myScaler.y);
//        ofFill();
    
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
//    cam.begin();
    // can we add several cameras?
    // how do we navigate in the camera with the code?
    //        ofDrawAxis(200); // x , y are inverted, 100. 100. instead of going down, go up
    //
    
//    cam.end();
    
    
    img.draw(0, 0); // --------> draws modified image

//
//    ofEnableAlphaBlending();
//    ofSetColor(255,255,255,100);
//    newImage.draw(0,0); // image glitch
//    ofDisableAlphaBlending();
////
//    fbo.draw(0,0);

    
    gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
        ofSaveScreen(ofGetTimestampString() + ".png");
    }
    
    
}

//--------------------------------------------------------------

void ofApp::drawWarpedText2(string str, float x, float y, float width, float height) {
    ofRectangle bbox = font.getStringBoundingBox(str, 0, 0);
    ofRectangle target(x, y, width, height);
    ofPushMatrix();
    // make the top left corner where we want it
    ofTranslate(target.x, target.y);
    ofScale(target.width / bbox.width, target.height / bbox.height);
    // draw the bounding box
    // ofDrawRectangle(0, 0, bbox.width, bbox.height);
    font.drawString(str, -bbox.x, -bbox.y);
    ofPopMatrix();
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
