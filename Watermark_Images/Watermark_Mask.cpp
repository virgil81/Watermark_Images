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

	//cv::addWeighted(roi,0.8, _hideimage1,0.2,0, roi);

	//for si modificam roi
	for (size_t i = 0; i < hiddenimage.cols; i++) {
		for (size_t j = 0; j < hiddenimage.rows; j++) {
			uchar pixel1 = hiddenimage.at<cv::Vec<uchar, 3>>(j, i).val[0];
			uchar pixel2 = hiddenimage.at<cv::Vec<uchar, 3>>(j, i).val[1];
			uchar pixel3 = hiddenimage.at<cv::Vec<uchar, 3 >>(j, i).val[2];

			if (pixel1 == 255 && pixel2 == 255 && pixel3 == 255) {
				roi.at<cv::Vec<uchar, 3>>(j, i).val[0] = 192 +  0.5 * roi.at<cv::Vec<uchar, 3>>(j, i).val[0];
				roi.at<cv::Vec<uchar, 3>>(j, i).val[1] = 192 + 0.5 * roi.at<cv::Vec<uchar, 3>>(j, i).val[1];
				roi.at<cv::Vec<uchar, 3>>(j, i).val[2] = 192 + 0.5 * roi.at<cv::Vec<uchar, 3>>(j, i).val[2];
			}


		}
	}

	cv::namedWindow("result1", 0);
	cv::imshow("result1", _result1);
	cv::waitKey();
}
Watermark_Mask::~Watermark_Mask()
{
}
