#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	antebraco.load("imgs/arm.png");
	braco.load("imgs/arm.png");
	mao.load("imgs/hand.png");

	angAntebraco = 0;
	angBraco = 0;
	angMao = 0;

	mundo.translate(0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(106, 90, 205);
	ofDrawRectangle(350, 300, 300, 400);
	ofSetColor(255, 255, 255);

	ofPushMatrix();

	Matriz3 aux = Matriz3::rotate(angBraco);
	Matriz3 aux2 = Matriz3::translate(300, 300);
	mundo = Matriz3::rotate(angBraco) * Matriz3::translate(630, 315);
	ofMultMatrix(mundo.to4x4());
	mundo = Matriz3::translate(-13, -13);
	ofMultMatrix(mundo.to4x4());
	braco.draw(0,0);
	mundo = Matriz3::rotate(angAntebraco) * Matriz3::translate(123, 13);
	ofMultMatrix(mundo.to4x4());
	mundo = Matriz3::translate(-13, -13);
	ofMultMatrix(mundo.to4x4());
	antebraco.draw(0, 0);
	mundo = Matriz3::rotate(angMao) * Matriz3::translate(123, 12);
	ofMultMatrix(mundo.to4x4());
	mundo = Matriz3::translate(-13, -33);
	ofMultMatrix(mundo.to4x4());
	mao.draw(0, 0);

	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'Z' || key == 'z')
		angAntebraco += 5.0f;

	if (key == 'X' || key == 'x')
		angAntebraco -= 5.0f;

	if (key == 'Q' || key == 'q')
		angMao += 5.0f;

	if (key == 'E' || key == 'e')
		angMao -= 5.0f;

	if (key == 'A' || key == 'a')
		angBraco += 5.0f;

	if (key == 'S' || key == 's')
		angBraco -= 5.0f;
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
