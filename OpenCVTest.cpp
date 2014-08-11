// OpenCVTest.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include "opencv2\\opencv.hpp"

#include "opencv2\\opencv_lib.hpp"



int main(int argc, char** argv)
{
	int x, y;
	uchar p[3];

	IplImage* img = cvLoadImage(argv[1], 3);

	for (y = 0; y < img->height; y++){
		for (x = 0; x < img->width; x++){
			p[0] = img->imageData[img->widthStep*y + x * 3];
			p[1] = img->imageData[img->widthStep*y + x * 3+1];
			p[2] = img->imageData[img->widthStep*y + x * 3+2];
			img->imageData[img->widthStep * y + x * 3] = cvRound(p[0] * 0.6 + 10);
			img->imageData[img->widthStep * y + x * 3 + 1] = cvRound(p[1] * 1.0);
			img->imageData[img->widthStep * y + x * 3 + 2] = cvRound(p[2] * 0.0);
		}
	}



	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
	return 0;
}

