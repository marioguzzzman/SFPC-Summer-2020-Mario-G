#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    doSaveScreen = false;

    gui.setup();
    gui.add(x1.setup("x1", 141, 0, 300));
    gui.add(y1.setup("y1", 0, 0, 300));
    gui.add(x2.setup("x2", 12, 0, 300));
    gui.add(y2.setup("y2", 3, 0, 300));
    gui.add(scaleX.setup("scaleX", .3255, .050, 1));
    gui.add(scaleY.setup("scaleY", .229, .050, 1));
    gui.add(scaleDif.setup("scaleDif", 0.088, .050, 1));

    font.load("Merriweather-Light.ttf", 100, true, true, true); // we are adding more parameters to create vectors
    //    bool _bAntiAliased=true,
    //    bool _bFullCharacterSet=false, --> true
    //    bool makeContours=false, --> true
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(215, 202, 202);

    float scale = scaleX;
    float scale2 = scaleY;
    // float scale = mouseX * .001;

    // std::cout << "x: " << scale << endl;
    std::cout << "x: " << mouseX << endl;
    std::cout << "y: " << mouseY << endl;

    //------------------ ADDING VECTORS TYPOGRAPHY -------------------------

    for (int y = 0; y < 30; y++){

        int offset = y;

        for (int x = 0; x < 30; x++){

            //LINES
            // float lx1 = 0;
            // float ly1 = 100;
            // float lx2 = 45;
            // float ly2 = 55;

            // ofSetLineWidth(3);
            // ofDrawLine(x + lx1, y + ly1, x + lx2, y + ly2);

            // if( x % MAX(mouseX, 1) == 0){ //can not divide by cero
            //this creates a DIAGONAL
            // if ((x + offset) % 4 < 2){ // in here we are adding the row
                //This creates STRIPES
            if (x % 2 == 0){ // |0|0|0|
                ofSetColor(105, 124, 151);
                scale = scaleX;
                // scale = .324;

            }else{
                // if ( (x+offset) % 4 < 2){ // in here we are adding the row
                ofSetColor(98, 107, 132);
                scale = scaleX - scaleDif;
                // scale = .224;
            }
            
            // ofDrawCircle(x * 40 + 100, y * 40 + 100, 20);

            //------------------ LETTER
            // font.drawString("S", x * 40 + 100, y * 40 + 100);
            
            ofPushMatrix();
            vector<ofPath> pathsx = font.getStringAsPoints("S"); // Returns a vector of ofPaths
            ofTranslate(x * 40, y * 40);

            ofScale(scale, scale);
            for (int i = 0; i < pathsx.size(); i++){
                pathsx[i].draw();
            }

            // ofSetLineWidth(3);
            // ofDrawLine(0, 45, 35, 45);

            //LINES
            // float lx1 = 0;
            // float ly1 = 35;
            // float lx2 = 45;
            // float ly2 = 55;

            ofSetLineWidth(4);
            ofDrawLine(x + x1, y + y1, x + x2, y + y2);

            ofPopMatrix();
        }
    }

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

    if (key == 'x')
    {
        doSaveScreen = true;

        if (doSaveScreen)
        {
            ofSaveScreen(ofToString(ofGetFrameNum()) + ".png");
            doSaveScreen = false;

            //        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
            //        img.save("screenshot.png");
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    // ofPoint pt;
    // pt.set(x, y);
    // line.addVertex(pt);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // line.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
