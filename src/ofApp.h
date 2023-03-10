#pragma once

#include "ofMain.h"
#include "grid.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
        void makeGrid(int x, int y, int dim);
        void markovRun();
    
    int grid_spacing;
    vector <Grid> all_grids;
    ofTrueTypeFont font;
    bool run_once;
    int draw_x, draw_y, draw_dim;
    int square_size;
    vector <ofColor> result;
    ofColor selected_color;
    int color_select_indicator;
    
};
