#pragma once
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
class Watermark_Manager
{
public:
	Watermark_Manager();
	Watermark_Manager(std::string path, std::string new_file, int nobits = 6);
	void Watermark_start();
	void Watermark_decrypt();
	~Watermark_Manager();
private:
	cv::Mat _image;
	cv::Mat _hideimage;
	cv::Mat _result;
	int _nobits;
};

