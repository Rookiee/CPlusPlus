#include "highgui.h"

int main() {
    cvNamedWindow("camera");
//    CvCapture * capture = cvCreateCameraCapture(-1);
    CvCapture * capture =  cvCreateFileCapture("/Users/Haoyang/Downloads/lieri.rmvb");
    IplImage * frame;
    
    while(1) {
        frame = cvQueryFrame(capture);
        if(!frame)
            break;
        cvShowImage("camera",frame);
        char c = cvWaitKey(200);
        if(c==27)
            break;
        
    }
    
    cvReleaseCapture(&capture);
    cvDestroyWindow("camera");
    return 0;
}