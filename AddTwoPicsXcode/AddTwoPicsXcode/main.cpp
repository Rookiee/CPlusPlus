//
//  main.cpp
//  AddTwoPicsXcode
//
//  Created by XieHaoyang on 12/15/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include <iostream>

#include "opencv.hpp"
#include "/usr/local/include/opencv2/highgui/highgui.hpp"
#include "/usr/local/include/opencv2/core/core.hpp"

using namespace std;
using namespace cv;
int main(int argc, const char * argv[]) {
    Mat image1 = imread("/Users/Haoyang/Downloads/boldt.jpg");
    if( !image1.data) {
        cerr << "Error" << endl;
        EXIT_FAILURE;
    }
    Mat image2 = imread("/Users/Haoyang/Downloads/rain.jpg");
    if( !image2.data) {
        cerr << "Error" << endl;
        EXIT_FAILURE;
    }
}
