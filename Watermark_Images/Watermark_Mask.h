#pragma once
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

class Watermark_Mask
{
public:
	Watermark_Mask();
	Watermark_Mask(std::string path, std::string new_file);
	void Watermark_start1();
	~Watermark_Mask();

private:
	cv::Mat _image1;
	cv::Mat _hideimage1;
	cv::Mat _result1;
};

