#pragma once

#include "ofMain.h"
using namespace glm;

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
		
		//light and mesh:
		ofMesh mesh;
		ofLight light; 
		void Flower(ofMesh &mesh); 

		ofEasyCam camera;

		//circle:
		float rad = 30; 
		float len = 3; 
		int petalnr = 50; 

		//current circle state and coordinates
		ofPoint pos; 
		ofPoint circleX, circleY, circleZ; 

		//increase the size:
		float size;
		
};
