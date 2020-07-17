#include "ofApp.h"


// This example compares the incoming frame, vs the background


//Steps for grabber
// 1 Declare
// 2 Update // grabber.update();
// 3 Draw //grabber.draw(0,0);

//--------------------------------------------------------------
void ofApp::setup(){
   
    grabber.listDevices();  //uncomment to work on mac
    grabber.setDeviceID(1);  //uncomment to work on mac
    
    grabber.initGrabber(640, 480); //if things look weird, change this
    
    //
    camGray.allocate(grabber.getWidth(),
                     grabber.getHeight(),
                     OF_IMAGE_GRAYSCALE);
    
    bgGray.allocate(grabber.getWidth(),
                    grabber.getHeight(),
                    OF_IMAGE_GRAYSCALE);
    
    // Allocate the difference
    diffImg.allocate(grabber.getWidth(),
                    grabber.getHeight(),
                    OF_IMAGE_GRAYSCALE);
    
    
    threshImg.allocate(grabber.getWidth(),
                      grabber.getHeight(),
                      OF_IMAGE_GRAYSCALE);
    
    bRecordBg = true; // record the background on the first frame
}

//--------------------------------------------------------------
void ofApp::update(){

    // second step of grabber in update
    grabber.update();
    
    // GRAY CAM
    if (grabber.isFrameNew()){
        convertColor(grabber,camGray, CV_RGB2GRAY ); // convert color image int grayscale
        camGray.update();
        
    //BACKGROUND --> has a toggle with space
    // will allow to record the background to separate
        if (bRecordBg){
            bgGray.setFromPixels(camGray.getPixels()); // takes data from the camgrey and takes it to bgGrey only on certain frames
            bgGray.update();
            bRecordBg = false;
        }
        
        // ansolute difference between grey and bggrey
        // important becuase we can threshold 
        absdiff(camGray, bgGray, diffImg); // ansolute difference between 0 amd 255
        diffImg.update();
        
        //Allocate
        threshImg.setFromPixels(diffImg.getPixels()); // copy the diffImage
        threshold(threshImg, mouseX);
        threshImg.update();
        
        finder.setSortBySize(true);// first blon will be the largest
        //finder.setMinArea(10); // problem if you sort by size
        
        finder.findContours(threshImg); // find the contours
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofScale(0.5, 0.5); // scale down
    
    ofSetColor(80);
    
    // third step of grabber in draw
    grabber.draw(0,0);

    ofSetColor(255);
    
    camGray.draw(grabber.getWidth(), 0);    // Draw to the rigth side of main video
    bgGray.draw(0, grabber.getHeight());    // draw the background under the main video
    
    diffImg.draw(grabber.getWidth(), grabber.getHeight()); /// also drawing it
    
    // Threshold
    threshImg.draw(grabber.getWidth()*2, 0);
    
    // what is this?
    if (finder.size() > 0){
        finder.getPolyline(0).draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ' ){
        bRecordBg = true; // record the background when hit space
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
