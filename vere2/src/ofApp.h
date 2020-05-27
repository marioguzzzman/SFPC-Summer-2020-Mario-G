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
    
    
        int attempt;
    
        ofImage img;
        bool doSaveScreen;
    
        string caseName;
    
        ofxPanel gui;
        ofxFloatSlider rectSize;
        ofxFloatSlider mapx1;
        ofxFloatSlider mapx2;
        ofxFloatSlider mapy1;
        ofxFloatSlider mapy2;
        ofxFloatSlider overRect;
        ofxFloatSlider overlapX;
		
};
