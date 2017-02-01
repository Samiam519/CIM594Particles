
// Example from Zach Lieberman, http://github.com/ofZach/algo2012
// https://github.com/ofZach/algo2012/tree/master/week4/multiParticles


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetBackgroundColor(255,0,0);
    counter = 0;
    speed = 50;
    for (int i = 0; i < 500; i++){
        Particle myParticle;
        float vx = ofRandom(-speed,speed);
        float vy = ofRandom(-speed,speed);
        myParticle.setInitialCondition(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
        // more interesting with diversity :)
        // uncomment this:
        myParticle.damping = ofRandom(0.01, 0.05);
        particles.push_back(myParticle);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
        if(counter == 60){
            ofSetBackgroundColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
            counter = 0;
        }
        counter++;    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        //particles[i].addForce(0,0.04);  // gravity
        particles[i].bounceOffWalls();
        particles[i].addDampingForce();
        particles[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < particles.size(); i++){
        //change color based on velocity
        int velocity = 127*((particles[i].vel.x + particles[i].vel.y)/2);
        ofSetColor(velocity, velocity, velocity);
        //change opactiy based on velocity
        if(particles[i].vel.x < 10 || particles[i].vel.y < 10){
            //decrease opacity
            ofSetColor(velocity,velocity,velocity,(255*velocity)/10);
            if (particles[i].vel.x == 0 && particles[i].vel.y == 0){
                //erase
                particles.pop_back();
            }
        }
        
        //draw particles
        particles[i].draw();
    }

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
    for (int i = 0; i < particles.size(); i++){
        float vx = ofRandom(-speed,speed);
        float vy = ofRandom(-speed,speed);
        particles[i].setInitialCondition(mouseX,mouseY,vx, vy);
    }
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
