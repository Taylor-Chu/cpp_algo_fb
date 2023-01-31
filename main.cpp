#include <Eigen/Core>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/eigen.hpp>

#include <algorithm>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    // string image_path = samples::findFile("starry_night.jpg");
    string image_path = "../images/Lenna.png";
    Mat img = imread(image_path, cv::IMREAD_GRAYSCALE);
    if(img.empty())
    {
        cout << "Could not read the image: " << image_path << endl;
        return 1;
    }

    // convert img to Eigen matrix
    // map the image data to an Eigen matrix
    // https://stackoverflow.com/questions/41596879/opencv-to-eigen-conversion
    // https://stackoverflow.com/questions/41596879/opencv-to-eigen-conversion/41600010#41600010
    // https://stackoverflow.com/questions/41596879/opencv-to-eigen-conversion/41600010#41600010

    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> img_eigen;

    cv2eigen(img, img_eigen);
    Mat dst;
    eigen2cv(img_eigen, dst);

    // Eigen::Matrix img_eigen;
    // void cv2eigen(img, img_eigen);
    // Eigen::Map<Matrix4f> eigenT( img.data() ); 

    // cout << "The image is of rows " << img.rows() <<  endl;
    // cout << "The image is of cols " << img.cols() <<  endl;
    // imshow("Display window", img);
    // int k = waitKey(0); // Wait for a keystroke in the window
    // if(k == 's')
    // {
    imwrite("../images/Lenna_bw_eigen.png", dst);
    // }
    return 0;
}