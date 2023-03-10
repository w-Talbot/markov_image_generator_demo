#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(150, 150, 150);
    
    selected_color = ofColor(255);
    color_select_indicator = 0;

    grid_spacing = 50;
    font.load("franklinGothic.otf", 10);
    
    draw_x = 100;
    draw_y = 100;
    draw_dim = 160;
    
    square_size = draw_dim / 10;
    
    //Create 5 grids for drawing into
    for(int i = 0; i < 10; i+=2){
        makeGrid(draw_x * i + grid_spacing, draw_y, draw_dim);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //Draw the 5 grids for drawing into
    ofNoFill();
    ofSetColor(255);
    for(int c = 0; c < 10; c+=2){
        ofDrawRectangle(draw_x * c + grid_spacing, draw_y, draw_dim, draw_dim);
        int new_x = draw_x * c + grid_spacing;
        for(int i = 0; i < 10; i++){
            ofSetLineWidth(2);
            ofDrawLine(i * square_size + new_x, draw_y, i * square_size + new_x, draw_y + draw_dim);
            ofDrawLine(new_x, i * square_size + draw_y, new_x + draw_dim, i * square_size + draw_y);
        }
    }
    
    //Draw the drawing grids with fill/color
    for(int j = 0; j < 5; j++){
        for(int k = 0; k < 100; k++){
            ofPushView();
            ofFill();
            ofSetColor(all_grids[j].rgb[k]);
            ofDrawRectangle(all_grids[j].x[k], all_grids[j].y[k], square_size - 2, square_size - 2);
            ofPopView();
        }
    }
    
    ofSetColor(0);
    ofNoFill();
    ofDrawRectangle(ofGetWidth()/2 - (draw_dim /2), draw_y * 3, draw_dim, draw_dim);
    
    
    //if the markov_run has been called and pushes points into result, draw them
    if(result.size() > 1){

        int r_x = ofGetWidth()/2 - (draw_dim/2);
        int r_y = draw_y * 3;

        int val = 0;
        for(int f = 0; f < 10; f++){
            for(int g = 0; g < 10; g++){
                ofFill();
                ofSetColor(result[val]);
                ofDrawRectangle(f * square_size + r_x, g * square_size + r_y, square_size, square_size);
                val +=1;
            }

        }
    }
    
    //Draw the color palette:
    ofFill();
    //white
    ofSetColor(255);
    ofDrawRectangle(0, 300, 50, 50);
    //red
    ofSetColor(255,0,0);
    ofDrawRectangle(50, 300, 50, 50);
    //green
    ofSetColor(0,255,0);
    ofDrawRectangle(100, 300, 50, 50);
    //black
    ofSetColor(0);
    ofDrawRectangle(0, 350, 50, 50);
    //blue
    ofSetColor(0,0,255);
    ofDrawRectangle(50, 350, 50, 50);
    //YEllow
    ofSetColor(255,255,0);
    ofDrawRectangle(100, 350, 50, 50);
    
    switch (color_select_indicator) {
        case 1:
            //white
            ofPushStyle();
            ofNoFill();
            ofSetLineWidth(4);
            ofSetColor(0);
            ofDrawRectangle(0, 300, 50, 50);
            ofPopStyle();
            break;
        case 2:
            //red
            ofPushStyle();
            ofNoFill();
            ofSetLineWidth(4);
            ofSetColor(0 );
            ofDrawRectangle(50, 300, 50, 50);
            ofPopStyle();
            break;
        case 3:
            //green
            ofPushStyle();
            ofNoFill();
            ofSetLineWidth(4);
            ofSetColor(0 );
            ofDrawRectangle(100, 300, 50, 50);
            ofPopStyle();
            break;
        case 4:
            //black
            ofPushStyle();
            ofNoFill();
            ofSetLineWidth(4);
            ofSetColor(255 );
            ofDrawRectangle(0, 350, 50, 50);
            ofPopStyle();
            break;
        case 5:
            //blue
            ofPushStyle();
            ofNoFill();
            ofSetLineWidth(4);
            ofSetColor(0 );
            ofDrawRectangle(50, 350, 50, 50);
            ofPopStyle();
            break;
        case 6:
            //yellow
            ofPushStyle();
            ofNoFill();
            ofSetLineWidth(4);
            ofSetColor(0 );
            ofDrawRectangle(100, 350, 50, 50);
            ofPopStyle();
            break;
            
        default:
            
            break;
    }
    
    
    ofSetColor(200);
    font.drawString("Press 'r' to run,\n'c' to clear,\nor 'n' to generate\n from the same drawings", 30, 25);
    
    
}
//--------------------------------------------------------------
void ofApp::makeGrid(int x, int y, int dim){

    Grid grid;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j ++){
            grid.x.push_back(i * square_size + x); //x location
            grid.y.push_back(j * square_size + y); //y
            grid.f.push_back(0); //color value of square (black and white to begin)
            grid.rgb.push_back(ofColor(255));
        }
    }

    
    all_grids.push_back(grid);
}

//--------------------------------------------------------------
void ofApp::markovRun(){

    for(int i = 0; i < 100; i++){
        int rand = ofRandom(5);

        result.push_back(all_grids[rand].rgb[i]);

    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'r' ){
        markovRun();
    }
    if(key == 'n' ){
        result.clear();
        markovRun();
    }
    
    if(key == 'c' ){
        
        for(int i = 0; i < 5; i ++){
            for(int j = 0; j < 100; j++){
                all_grids[i].rgb[j]=ofColor(255);
            }
        }
        
        result.clear();
    }
  
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    //Number 0
    if(mouseX > grid_spacing && mouseX < grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[0].x.size(); i++){
                if(
                   x > all_grids[0].x[i] &&
                   x < all_grids[0].x[i] + square_size &&
                   y > all_grids[0].y[i] &&
                   y < all_grids[0].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[0].rgb[i] = ofColor(selected_color);
                   
                    all_grids[0].f[i] += 1;
            
                    std::cout << "x: " << all_grids[0].x[i] << " y: " << all_grids[0].y[i] << endl;
                }
        }
        
    
    }
    //Number 1
    if(mouseX > draw_x * 2 + grid_spacing && mouseX < draw_x * 2 + grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[1].x.size(); i++){
                if(
                   x > all_grids[1].x[i] &&
                   x < all_grids[1].x[i] + square_size &&
                   y > all_grids[1].y[i] &&
                   y < all_grids[1].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[1].rgb[i] = ofColor(selected_color);
                   
                    all_grids[1].f[i] += 1;
            
                    std::cout << "x: " << all_grids[1].x[i] << " y: " << all_grids[1].y[i] << endl;
                }
        }
    
    }
    //Number 2
    if(mouseX > draw_x * 4 + grid_spacing && mouseX < draw_x * 4 + grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[2].x.size(); i++){
                if(
                   x > all_grids[2].x[i] &&
                   x < all_grids[2].x[i] + square_size &&
                   y > all_grids[2].y[i] &&
                   y < all_grids[2].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[2].rgb[i] = ofColor(selected_color);
                   
                    all_grids[2].f[i] += 1;
            
                    std::cout << "x: " << all_grids[2].x[i] << " y: " << all_grids[2].y[i] << endl;
                }
        }
    
    }
    //Number 3
    if(mouseX > draw_x * 6 + grid_spacing && mouseX < draw_x * 6 + grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
       
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[3].x.size(); i++){
                if(
                   x > all_grids[3].x[i] &&
                   x < all_grids[3].x[i] + square_size &&
                   y > all_grids[3].y[i] &&
                   y < all_grids[3].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[3].rgb[i] = ofColor(selected_color);
                   
                    all_grids[3].f[i] += 1;
            
                    std::cout << "x: " << all_grids[3].x[i] << " y: " << all_grids[3].y[i] << endl;
                }
        }
    
    }
    //Number 4
    if(mouseX > draw_x * 8 + grid_spacing && mouseX < draw_x * 8 + grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[4].x.size(); i++){
                if(
                   x > all_grids[4].x[i] &&
                   x < all_grids[4].x[i] + square_size &&
                   y > all_grids[4].y[i] &&
                   y < all_grids[4].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[4].rgb[i] = ofColor(selected_color);
                   
                    all_grids[4].f[i] += 1;
            
                    std::cout << "x: " << all_grids[4].x[i] << " y: " << all_grids[4].y[i] << endl;
                }
        }
        
    }
   
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //Number 0
    if(mouseX > grid_spacing && mouseX < grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[0].x.size(); i++){
                if(
                   x > all_grids[0].x[i] &&
                   x < all_grids[0].x[i] + square_size &&
                   y > all_grids[0].y[i] &&
                   y < all_grids[0].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[0].rgb[i] = ofColor(selected_color);
                   
                    all_grids[0].f[i] += 1;
            
                    std::cout << "x: " << all_grids[0].x[i] << " y: " << all_grids[0].y[i] << endl;
                }
        }
        
    
    }
    //Number 1
    if(mouseX > draw_x * 2 + grid_spacing && mouseX < draw_x * 2 + grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[1].x.size(); i++){
                if(
                   x > all_grids[1].x[i] &&
                   x < all_grids[1].x[i] + square_size &&
                   y > all_grids[1].y[i] &&
                   y < all_grids[1].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[1].rgb[i] = ofColor(selected_color);
                   
                    all_grids[1].f[i] += 1;
            
                    std::cout << "x: " << all_grids[1].x[i] << " y: " << all_grids[1].y[i] << endl;
                }
        }
    
    }
    //Number 2
    if(mouseX > draw_x * 4 + grid_spacing && mouseX < draw_x * 4 + grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[2].x.size(); i++){
                if(
                   x > all_grids[2].x[i] &&
                   x < all_grids[2].x[i] + square_size &&
                   y > all_grids[2].y[i] &&
                   y < all_grids[2].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[2].rgb[i] = ofColor(selected_color);
                   
                    all_grids[2].f[i] += 1;
            
                    std::cout << "x: " << all_grids[2].x[i] << " y: " << all_grids[2].y[i] << endl;
                }
        }
    
    }
    //Number 3
    if(mouseX > draw_x * 6 + grid_spacing && mouseX < draw_x * 6 + grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
       
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[3].x.size(); i++){
                if(
                   x > all_grids[3].x[i] &&
                   x < all_grids[3].x[i] + square_size &&
                   y > all_grids[3].y[i] &&
                   y < all_grids[3].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[3].rgb[i] = ofColor(selected_color);
                   
                    all_grids[3].f[i] += 1;
            
                    std::cout << "x: " << all_grids[3].x[i] << " y: " << all_grids[3].y[i] << endl;
                }
        }
    
    }
    //Number 4
    if(mouseX > draw_x * 8 + grid_spacing && mouseX < draw_x * 8 + grid_spacing + draw_dim && mouseY > draw_y && mouseY < draw_y + draw_dim){
        
        //Rotate through colors when clicked:
        for(int i = 0; i < all_grids[4].x.size(); i++){
                if(
                   x > all_grids[4].x[i] &&
                   x < all_grids[4].x[i] + square_size &&
                   y > all_grids[4].y[i] &&
                   y < all_grids[4].y[i] + square_size){
            
                    
                    //maybe add colors later
                    all_grids[4].rgb[i] = ofColor(selected_color);
                   
                    all_grids[4].f[i] += 1;
            
                    std::cout << "x: " << all_grids[4].x[i] << " y: " << all_grids[4].y[i] << endl;
                }
        }
        
    }
    
    //COLOR SELECTION:
    //L -> R  w, r, g, bk, bl, y
    
    
    //white
    if(mouseX > 0 && mouseX < 50 && mouseY > 300 && mouseY < 350 ){
        selected_color = ofColor(255);
        color_select_indicator = 1;
    }
    //red
    if(mouseX > 50 && mouseX < 100 && mouseY > 300 && mouseY < 350 ){
        selected_color = ofColor(255,0,0);
        color_select_indicator = 2;
    }
    //green
    if(mouseX > 100 && mouseX < 150 && mouseY > 300 && mouseY < 350 ){
        selected_color = ofColor(0,255,0);
        color_select_indicator = 3;
    }
    //black
    if(mouseX > 0 && mouseX < 50 && mouseY > 350 && mouseY < 400 ){
        selected_color = ofColor(0);
        color_select_indicator = 4;
    }
    //blue
    if(mouseX > 50 && mouseX < 100 && mouseY > 350 && mouseY < 400 ){
        selected_color = ofColor(0,0,255);
        color_select_indicator = 5;
    }
    //yellow
    if(mouseX > 100 && mouseX < 150 && mouseY > 350 && mouseY < 400 ){
        selected_color = ofColor(255,255,0);
        color_select_indicator = 6;
    }
    
    
    
    
   
    
}

