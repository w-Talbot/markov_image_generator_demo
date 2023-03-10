//
//  grid.hpp
//  markov_image_generator_jan2023
//
//  Created by Wesley Talbot on 1/31/23.
//

#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>
#include "ofMain.h"

class Grid{
    
public:
    vector<int>x;
    vector<int>y;
    vector<int>f;
    vector<ofColor> rgb;
};

#endif /* grid_hpp */
