#pragma once

#include "ofMain.h"
#include "grid.hpp"

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
        void makeGrid(int x, int y, int dim);
        void markovRun();
    
    int grid_spacing;
    vector <Grid> all_grids;
    ofTrueTypeFont font;
    bool run_once;
    int draw_x, draw_y, draw_dim;
    int square_size;
    vector <int> result;
    
    bool test = true;
};
