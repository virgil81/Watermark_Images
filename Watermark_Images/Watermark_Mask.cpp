#include "Watermark_Mask.h"



Watermark_Mask::Watermark_Mask()
{
}

Watermark_Mask::Watermark_Mask(std::string path, std::string new_file)
{
	_image1 = cv::imread(path);
	_hideimage1 = cv::imread(new_file);
}	//cv::resize(_hideimage1, _hideimage1, _image1.size());


void Watermark_Mask::Watermark_start1() {
	_result1 = _image1.clone();
	cv::Mat hiddenimage = _hideimage1.clone();

	cv::Mat roi = _result1(cv::Rect(_result1.cols - _hideimage1.cols,
		_result1.rows - _hideimage1.rows, _hideimage1.cols, _hideimage1.rows));

	//cv::addWeighted(roi,0.9, _hideimage1,0.1,0, roi);

	//for si modificam roi
	cv::namedWindow("result1", 0);
	cv::imshow("result1", _result1);
	cv::waitKey();
}
Watermark_Mask::~Watermark_Mask()
{
}
