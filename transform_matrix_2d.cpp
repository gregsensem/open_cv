#include "opencv2/opencv.hpp"
#include <iostream>

#define Scale(s) (cv::Mat_<double>(2, 2) << s, 0, 0, s)
#define Rotation(r) (cv::Mat_<double>(2, 2) << cos(r), -sin(r), sin(r), cos(r))
#define Translation(x, y) (cv::Mat_<double>(2, 3) << 1, 0, x, 0, 1, y)

void display(cv::Mat &m)
{
    for(int i = 0; i < m.rows; i++)
    {
        const double* mi = m.ptr<double>(i);
        for(int j = 0; j < m.cols; j++)
            std::cout << mi[j] << '\t';
        std::cout << std::endl;
    }
}

int main()
{
    cv::Mat r = Rotation(CV_PI/2);
    cv::Mat s = Scale(10);
    cv::Mat t = Translation(3, 3);

    //Rotate then scale point p(2,2)
    cv::Mat p = (cv::Mat_<double>(2,1) << 2, 2);
    cv::Mat p_rs = s * r * p; 
    std::cout << "the rotated and scaled point is :" << std::endl;
    display(p_rs);

    //Translate point p2 (2, 2, 1)
    cv::Mat p2 = (cv::Mat_<double>(3,1) << 2, 2, 1);
    cv::Mat p2_t = t * p2;

    //rotate and translate point p2
    cv::Mat p2_rt = r * t * p2;
    std::cout << "the translated and rotated point is :" << std::endl;
    display(p2_rt);

    //combine rotate & tanslate matrix together
    cv::Mat Rt;
    cv::Mat t_ = (cv::Mat_<double>(2,1) << 10, 10);
    cv::hconcat(r, t_, Rt);
    cv::Mat p2_Rt = Rt * p2;
    std::cout << "The Rt matrix is : " << std::endl;
    display(Rt);
    std::cout << "the projected point p2_Rt is :" << std::endl;
    display(p2_Rt);

    //given p2_Rt, and Rt, find p2
    cv::Mat Rt_inv;
    cv::Mat third_row = (cv::Mat_<double>(1,3) << 0, 0, 1);
    cv::vconcat(Rt, third_row, Rt_inv);
    Rt_inv = Rt_inv.inv();
    cv::Mat p2_Rt_ = (cv::Mat_<double>(3,1) << 8, 12, 1);
    cv::Mat p2_recover = Rt_inv * p2_Rt_;

    std::cout << "The Rt_inv matrix is : " << std::endl;
    display(Rt_inv);
    std::cout << "the original point is :" << std::endl;
    display(p2_recover);

    return 0;
}