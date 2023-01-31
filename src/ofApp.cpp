#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grid_spacing = 50;
    font.load("franklinGothic.otf", 20);
    run_once = true;
    draw_x = 100;
    draw_y = 100;
    draw_dim = 160;
    
    square_size = draw_dim / 10;
    
    
    for(int i = 0; i < 10; i+=2){
        makeGrid(draw_x * i + grid_spacing, draw_y, draw_dim);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
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
    
    for(int j = 0; j < 5; j++){
        for(int k = 0; k < 100; k++){
            ofPushView();
            ofFill();
            if(all_grids[j].f[k] == 0){
                ofSetColor(0);
            }else{
                ofSetColor(255);
            }
            ofDrawRectangle(all_grids[j].x[k], all_grids[j].y[k], square_size - 2, square_size - 2);
            ofPopView();
        }
    }
    
    ofNoFill();
    ofDrawRectangle(ofGetWidth()/2 - (draw_dim /2), draw_y * 3, draw_dim, draw_dim);
    
    if(result.size() > 1){
        
        int r_x = ofGetWidth()/2 - (draw_dim/2);
        int r_y = draw_y * 3;
        
        int val = 0;
        for(int f = 0; f < 10; f++){
            for(int g = 0; g < 10; g++){
                ofFill();
                if(result[val] == 0){
                    ofSetColor(0);
                }else{
                    ofSetColor(255);
                }
                
                ofDrawRectangle(f * square_size + r_x, g * square_size + r_y, square_size, square_size);
                val +=1;
            }
            
        }
    }
    
    
    ofSetColor(255, 0, 0);
    font.drawString("x: " + ofToString(mouseX) + " y: " + ofToString(mouseY), mouseX, mouseY);
    
    
}
//--------------------------------------------------------------
void ofApp::makeGrid(int x, int y, int dim){

    Grid grid;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j ++){
            grid.x.push_back(i * square_size + x);
            grid.y.push_back(j * square_size + y);
            grid.f.push_back(0);
        }
    }

    
    all_grids.push_back(grid);
}

//--------------------------------------------------------------
void ofApp::markovRun(){

    for(int i = 0; i < 100; i++){
        int rand = ofRandom(5);
        
        result.push_back(all_grids[rand].f[i]);
        
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'r' || 'm'){
        markovRun();
    }
    if(key == 'c' || 'C'){
        result.clear();
        all_grids.clear();
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
                    //all_grids[0].f +=1;
                   
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
                    //all_grids[0].f +=1;
                   
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
                    //all_grids[0].f +=1;
                   
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
                    //all_grids[0].f +=1;
                   
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
                    //all_grids[0].f +=1;
                   
                    all_grids[4].f[i] += 1;
            
                    std::cout << "x: " << all_grids[4].x[i] << " y: " << all_grids[4].y[i] << endl;
                }
        }
        
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
