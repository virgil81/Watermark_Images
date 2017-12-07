#pragma once
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
class Watermark_Manager
{
public:
	Watermark_Manager();
	~Watermark_Manager();
private:
	cv::Mat _image;
};

