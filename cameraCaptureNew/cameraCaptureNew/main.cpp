//
//  main.cpp
//  cameraCaptureNew
//
//  Created by XieHaoyang on 12/16/15.
//  Copyright © 2015 XieHaoyang. All rights reserved.
//

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>


using namespace cv;
int main(int argc, const char * argv[]) {
    // insert code here...
    Mat image = imread("/Users/Haoyang/Downloads/boldt.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    namedWindow("Test");
    imshow("Test",image);
    waitKey();
    
    std::cout << "Hello, World!\n";
    return 0;
}
