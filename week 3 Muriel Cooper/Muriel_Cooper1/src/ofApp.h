#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage img;
    bool doSaveScreen;
    
    ofEasyCam cam;
    ofTrueTypeFont font;
    
    ofxPanel gui;
    ofxIntSlider x;
    ofxIntSlider y;
    ofxIntSlider z;
    ofxIntSlider z2;
    ofxIntSlider z3;
    ofxIntSlider z4;
    ofxFloatSlider scaleX;


    
    
    
};
