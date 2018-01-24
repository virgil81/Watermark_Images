#include "Watermark_Manager.h"



Watermark_Manager::Watermark_Manager()
{
}

Watermark_Manager::Watermark_Manager(std::string path,std::string new_file)
{
	_image = cv::imread(path);
	_hideimage = cv::imread(new_file);
	cv::resize(_hideimage, _hideimage, _image.size());
}

void Watermark_Manager::Watermark_start()
{
	_result = _image.clone();
	cv::Mat hiddenimage = _hideimage.clone();


	for (size_t i = 0; i < _image.cols; i++)
	{
		for (size_t j = 0; j < _image.rows; j++)
		{
			//uchar val = _image.at<uchar>(j, i);
			//if (val != 0)
			_result.at<cv::Vec<uchar, 3> >(j, i).val[0] = _image.at<cv::Vec<uchar, 3> >(j, i).val[0] >> 2;
			_result.at<cv::Vec<uchar, 3> >(j, i).val[1] = _image.at<cv::Vec<uchar, 3> >(j, i).val[1] >> 2;
			_result.at<cv::Vec<uchar, 3> >(j, i).val[2] = _image.at<cv::Vec<uchar, 3> >(j, i).val[2] >> 2;

			_result.at<uchar>(j, i) = _result.at<uchar>(j, i) << 2;

			hiddenimage.at<uchar>(j, i) = _hideimage.at<uchar>(j, i) >> 6;

			_result.at<uchar>(j, i) = _result.at<uchar>(j, i) | hiddenimage.at<uchar>(j, i);
		}
	}
}
void Watermark_Manager::Watermark_decrypt()
{
	
	cv::Mat hiddenimage = _result.clone();


	for (size_t i = 0; i < _result.cols; i++)
	{
		for (size_t j = 0; j < _result.rows; j++)
		{
			
			hiddenimage.at<cv::Vec<uchar,3>>(j, i).val[0] = _result.at<cv::Vec<uchar,3>>(j, i).val[0] << 6;
			hiddenimage.at<cv::Vec<uchar, 3>>(j, i).val[1] = _result.at<cv::Vec<uchar, 3>>(j, i).val[1] << 6;
			hiddenimage.at<cv::Vec<uchar, 3>>(j, i).val[2] = _result.at<cv::Vec<uchar, 3>>(j, i).val[2] << 6;


		}
	}
	cv::namedWindow("result", 0);
	cv::imshow("result", hiddenimage);
	cv::waitKey();
}

Watermark_Manager::~Watermark_Manager()
{
}
