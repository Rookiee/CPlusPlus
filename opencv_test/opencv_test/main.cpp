#include "highgui.h"

//#include "cv.h"
//#include "cxcore.h"

int main(int argc, char * argv[]) {
    
/*    IplImage * src = NULL;
    src = cvLoadImage("/Users/Haoyang/Downloads/pic.jpg",2 | 4);
    cvNamedWindow("show_image",0);  // 创建窗口
    cvShowImage("show_image",src);   // 在show_ image中显示图片
    cvWaitKey(0);   //等待 （大于0：毫秒）
    cvReleaseImage(&src);   //释放图片
    cvDestroyWindow("show_image"); //释放窗口
 */
    
//    int i,j;
//    double a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
//    CvMat Ma = cvMat(3,4,CV_32FC1,a);
//    CvMat * M = cvCreateMat(3,4,CV_32FC1);
//    cvmSet(M,i,j,2.0);
//    t = cvmGet(M,i,j);
    CvMat * M = cvCreateMat(4, 4, CV_32FC(1));
    int step = M->step/sizeof(float);
    float * data = M->data.fl;
    return 0;
}