#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){

    //Read image
    Mat image = imread("../assets/putin.jpg");

    //convert to YcrCb color space
    Mat imageYcb;
    cvtColor(image, imageYcb, COLOR_BGR2YCrCb);

    //split into channels
    vector<Mat> channels(3);
    split(imageYcb, channels);

    //histogram equalizarion of Y channel
    equalizeHist(channels[0], channels[0]);

    //merge the channels
    merge(channels, imageYcb);

    //convert back to BGR color space
    Mat result;
    cvtColor(imageYcb, result, COLOR_YCrCb2BGR);

    //create windows to display images
    namedWindow("image", WINDOW_NORMAL);
    namedWindow("result", WINDOW_NORMAL);

    //display images
    imshow("image", image);
    imshow("result", result);

    //press esc to exit the program
    waitKey(0);

    //close all the opended windows
    return 0;
}