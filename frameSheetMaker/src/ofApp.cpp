#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofDirectory dir;
    dir.listDir("frames");
    dir.sort();
    
    for (int i = 0; i < dir.size(); i++) {

       ofImage img;
       frames.push_back(img);
       frames.back().load(dir.getPath(i));
        
           cout << "loaded" << i << " of " << dir.size() << endl;

    }
    
    
    // >> Add YOUR frame image pixel size to the "originalSize" variable
    float originalSize = 800;
    float scale = originalSize/130; //125;
    
    float sheetWidth = 595*scale;
    float sheetHeight = 842*scale;
    
    sheet.allocate(sheetWidth,sheetHeight, GL_RGBA);
    
    int border = 0; //12*scale;
        
    ix = border;
    iy = border;
      
      sheet.begin();
          ofBackground(255,0);
            
          for (int i = 0; i < frames.size(); i++){
                
                frames[i].draw(ix,iy);
                
                imageWidth = frames[i].getWidth();
                imageHeight = frames[i].getHeight();
                
              ix = ix + (imageWidth + border);
                
                    if (ix > sheetWidth - (imageWidth + border)){
                        iy = iy + (imageHeight + border);
                        ix = border;
                    }
            }

      sheet.end();
      
      ofPixels saveSheet;
      sheet.readToPixels(saveSheet);
      ofSaveImage(saveSheet, "sheet.png");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
