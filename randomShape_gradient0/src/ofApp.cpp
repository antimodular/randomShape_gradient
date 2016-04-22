#include "ofApp.h"



float radialNoiseCursor;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetVerticalSync(true);
    
    pix.allocate(ofGetWidth(), ofGetHeight(), 4);
    img.allocate(ofGetWidth(), ofGetHeight(),OF_IMAGE_COLOR); //_ALPHA);
    
     vector<ofPolyline> pLine;
    
    ofPath myEllipse;
    myEllipse.ellipse(ofGetWidth()/2, ofGetHeight()/2, 200, 400);
    myEllipse.setCircleResolution(100);
    pLine = myEllipse.getOutline();
  
   
    for(int i=1 ; i<pLine[0].size(); i++){
        myShape.addVertex(pLine[0][i]);
    }

    myShape.close();
    
    radialNoiseCursor = 0;
}


//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){

    polylineGradient();
    
}

void ofApp::polylineGradient(){
    

  

    float noiseStep = 0.2; //0.01 - 0.15
    float noiseAmount = 0.8; //0-1
    
    for(int i=0; i<myShape.size();i++){
//        pLine[0][i] += ofRandom(-5,5);
        myShape[i] += noiseAmount * ofSignedNoise( radialNoiseCursor ) * 5;
        radialNoiseCursor += noiseStep;
        
    }
    
      int a = 1;
//    pix.clear();
    for(int x = 0; x<ofGetWidth()-a; x+=a){
        for(int y = 0; y<ofGetHeight()-a; y+=a){
            ofPoint myP = ofPoint(x,y);
            
            if(myShape.inside(myP) == false){

            ofPoint closestPoint = myShape.getClosestPoint(myP);
            float dist = closestPoint.distance(myP);
//            int alpha = ofMap(dist,0,ofGetWidth()/2,0,255,true);
int alpha = ofMap(dist,0,ofGetWidth()/10,255,0,true);
//            ofDrawLine(closestPoint,myP);
                

                pix.setColor(x, y, ofColor(255,0,0,alpha));


            }else{
                pix.setColor(x, y, ofColor(255));
            }
        }
    }
    
    img.setFromPixels(pix);


    ofSetColor(255);
    img.draw(0, 0);
    ofPoint myP(mouseX,mouseY);
    ofPoint closestPoint = myShape.getClosestPoint(myP);
    ofSetColor(0,0,255);
    ofDrawLine(closestPoint,myP);
    
     myShape.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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