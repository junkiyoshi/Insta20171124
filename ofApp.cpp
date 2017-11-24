#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	this->fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update() {

	float radius = 10;

	this->fbo.begin();
	ofClear(0);

	for (int x = 0; x <= ofGetWidth(); x += 30) {
		for (int y = 0; y <= ofGetHeight(); y += 30) {
			ofNoFill();
			ofDrawCircle(x, y, 13);
			ofFill();
			ofDrawCircle(x, y, 15 * ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.015));
		}
	}

	this->fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->fbo.draw(0, 0);
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
