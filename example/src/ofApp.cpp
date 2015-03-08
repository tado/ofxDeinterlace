#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.loadMovie("source.mov");
    video.play();
    deinterlace = new ofxDeinterlace(video.getTextureReference());
    enableDeinterlace = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (enableDeinterlace == false) {
        video.draw(0, 0);
        ofDrawBitmapString("Deintarlace : OFF", 20, 40);
    } else {
        deinterlace->draw();
        ofDrawBitmapString("Deintarlace : ON", 20, 40);
    }
    ofDrawBitmapString("Press any key", 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (enableDeinterlace == false) {
        enableDeinterlace = true;
    } else {
        enableDeinterlace = false;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
