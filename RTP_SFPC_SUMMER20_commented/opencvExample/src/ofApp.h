#pragma once

#include "ofMain.h"
#include "ofxCv.h"


using namespace ofxCv; // using the name space to a clearer writing

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
    
    
        ofVideoGrabber grabber;  //1 first step of grabber
    
        ofImage camGray; // copy the data from grabber into grayscale
    
        ofImage bgGray; // image that represents the background
        bool bRecordBg = false; // to record the background
 
        ofImage diffImg;  // this will represent the difference
        ofImage threshImg; // trheshold
        ContourFinder finder; // fimd contour
		
};
