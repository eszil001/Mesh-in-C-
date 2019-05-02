#include "ofApp.h"
//project nr1 : THE MESH! 
//create flowers by pressing the key 'a' to make them bigger or 's' to make them smaller, 'd' clears the canvas
//--------------------------------------------------------------
void ofApp::setup(){

	size = 0.5;

    /* not using this anymore since I added rotation to the screen:
	camera.setPosition(vec3(0.0f, 8.0f, 24.0f));
	camera.setTarget(vec3(0.0f, 4.0f, 0.0f));
	camera.setFov(32.0f);
	camera.setNearClip(0.05f);
	camera.setFarClip(100.0f);
	*/

	//center:
	pos = ofPoint(0, 0, 0); 

	//coordinate matrix:
	circleX = ofPoint(1, 0, 0);
	circleY = ofPoint(0, 1, 0);
	circleZ = ofPoint(0, 0, 1);

	//light.setAmbientColor(size);
	//light.setSpecularColor(size);

	//enabling the light:
	light.enable(); 
	

	//the speed of how fast its moving, 60 will make it move faster:
	ofSetFrameRate(30); 
}

//--------------------------------------------------------------
void ofApp::update(){

	//calling the function I made which uses the mesh;
	Flower(mesh);
}

//--------------------------------------------------------------
void ofApp::draw(){

	//setting it up in the middle of the canvas:
	ofEnableDepthTest();
	ofBackground(0);
	ofPushMatrix(); 
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	//the rotation angle just as in the example given in the lecture:
	float time = ofGetElapsedTimef(); 
	float angle = time * 40; 
	ofRotate(angle, 0, 1, 0); 
	//-------------------------------

	//setting the flower to be fixed in the middle:
	ofTranslate(-mesh.getCentroid());
	mesh.draw();
	ofPopMatrix(); 
}
//--------------------------------------------------------------
void ofApp::Flower(ofMesh &mesh) {
	float time = ofGetElapsedTimef(); 

	//rotation and colors:
	float swirling = ofSignedNoise(time * 0.3 + 332.4);
	float rotation = 0.5;

    ofFloatColor color(ofNoise(time * 0.15),ofNoise(time * 0.001 ),ofNoise(time * 0.05));
	
	color.setSaturation(0.9); 
    color.setBrightness(1.0);


	//------------- setting the rotations and the pos of the cicle:
	circleX.rotate(swirling, circleZ);
	circleY.rotate(swirling, circleZ);
	circleX.rotate(rotation, circleY);
	circleZ.rotate(rotation, circleY);
	//the speed of how fast it grows in length:
	ofPoint move = circleZ * len;
	pos += move;
	//-------------

	//vertices
	for (int i = 0; i < petalnr; i++) {
		float angle = float(i) / petalnr * TWO_PI;

		float x = rad * cos(angle);
		float y = rad * sin(angle);
		
		//using the variable created "size" to change the size of the flower depending what key is pressed 'a' or 's':
		
		float distort = ofNoise(x * 0.2, y * 0.2, time * 0.2 + 30);
		distort = ofMap(distort, 1.4, 0.9, 0.9, size);
		x *= distort;
		y *= distort;

		//adding the color to the mesh:
		ofPoint pointy = circleX * x + circleY * y + pos;
		mesh.addVertex(pointy);
		mesh.addColor(color);
	}

	//Adding the triangles together in the for loop
	int base = mesh.getNumVertices() - 2 * petalnr;
	if (base >= 0) 
	{ 
		for (int i = 0; i < petalnr; i++){
			int a = base + i;
			int b = base + (i + 1) % petalnr;
			int c = petalnr + a;
			int d = petalnr + b;
			//to form the "flower shape":
			mesh.addTriangle(a, b, d); 
			mesh.addTriangle(a, d, c);
		}
		
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//changes the size = bigger, if pressed for a long time:
	if (key == 'a'){
		size += 0.05;
	}
	//changes the size = smaller:
	if (key == 's'){
		size -= 0.05;
	}
	//clears the "canvas" for a fresh start:
	if (key == 'd'){
		mesh.clear();
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
