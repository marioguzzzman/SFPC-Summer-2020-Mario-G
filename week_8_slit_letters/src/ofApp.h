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
    
    void drawWarpedText2(string str, float x, float y, float width, float height);
    
//    ofVideoGrabber grabber;
    vector < ofImage > images; //place holder to store last 100 frames
    ofImage img;
    
    //Camera
    ofVideoGrabber grabber;
    ofEasyCam cam;  // add easy cam
    
//    type
    ofTrueTypeFont font;
    string text;
    
    
//GLITCH 1
    ofImage original;
    ofImage saver;
    ofImage drawer;
    ofImage newImage;
    
    ofFbo fbo;


//    GUI
    ofxPanel gui;
    ofxIntSlider x;
    ofxIntSlider y;
    ofxIntSlider z;
    
};
