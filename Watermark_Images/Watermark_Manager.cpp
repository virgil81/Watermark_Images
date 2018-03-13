#include "Watermark_Manager.h"



Watermark_Manager::Watermark_Manager()
{
}

Watermark_Manager::Watermark_Manager(std::string path, std::string new_file, int nobits = 6)
{
	_image = cv::imread(path);
	_hideimage = cv::imread(new_file);
	cv::resize(_hideimage, _hideimage, _image.size());
	_nobits = nobits;

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
			_result.at<cv::Vec<uchar, 3> >(j, i).val[0] = _image.at<cv::Vec<uchar, 3> >(j, i).val[0] >> _nobits;
			_result.at<cv::Vec<uchar, 3> >(j, i).val[1] = _image.at<cv::Vec<uchar, 3> >(j, i).val[1] >> _nobits;
			_result.at<cv::Vec<uchar, 3> >(j, i).val[2] = _image.at<cv::Vec<uchar, 3> >(j, i).val[2] >> _nobits;

			_result.at<cv::Vec<uchar, 3> >(j, i).val[0] = _result.at<cv::Vec<uchar, 3> >(j, i).val[0] << _nobits;
			_result.at<cv::Vec<uchar, 3> >(j, i).val[1] = _result.at<cv::Vec<uchar, 3> >(j, i).val[1] << _nobits;
			_result.at<cv::Vec<uchar, 3> >(j, i).val[2] = _result.at<cv::Vec<uchar, 3> >(j, i).val[2] << _nobits;

			hiddenimage.at<cv::Vec<uchar, 3> >(j, i).val[0] = _hideimage.at<cv::Vec<uchar, 3> >(j, i).val[0] >> 8 - _nobits;
			hiddenimage.at<cv::Vec<uchar, 3> >(j, i).val[1] = _hideimage.at<cv::Vec<uchar, 3> >(j, i).val[1] >> 8 - _nobits;
			hiddenimage.at<cv::Vec<uchar, 3> >(j, i).val[2] = _hideimage.at<cv::Vec<uchar, 3> >(j, i).val[2] >> 8 - _nobits;



			_result.at<cv::Vec<uchar, 3> >(j, i).val[0] = _result.at<cv::Vec<uchar, 3> >(j, i).val[0] | hiddenimage.at<cv::Vec<uchar, 3> >(j, i).val[0];
			_result.at<cv::Vec<uchar, 3> >(j, i).val[1] = _result.at<cv::Vec<uchar, 3> >(j, i).val[1] | hiddenimage.at<cv::Vec<uchar, 3> >(j, i).val[1];
			_result.at<cv::Vec<uchar, 3> >(j, i).val[2] = _result.at<cv::Vec<uchar, 3> >(j, i).val[2] | hiddenimage.at<cv::Vec<uchar, 3> >(j, i).val[2];
		}
	}

	cv::namedWindow("result1", 0);
	cv::imshow("result1", _result);
	cv::waitKey();
}

void Watermark_Manager::Watermark_decrypt()
{

	cv::Mat hiddenimage = _result.clone();


	for (size_t i = 0; i < _result.cols; i++)
	{
		for (size_t j = 0; j < _result.rows; j++)
		{

			hiddenimage.at<cv::Vec<uchar, 3>>(j, i).val[0] = _result.at<cv::Vec<uchar, 3>>(j, i).val[0] << 8 - _nobits;
			hiddenimage.at<cv::Vec<uchar, 3>>(j, i).val[1] = _result.at<cv::Vec<uchar, 3>>(j, i).val[1] << 8 - _nobits;
			hiddenimage.at<cv::Vec<uchar, 3>>(j, i).val[2] = _result.at<cv::Vec<uchar, 3>>(j, i).val[2] << 8 - _nobits;


		}
	}
	cv::namedWindow("result2", 0);
	cv::imshow("result2", hiddenimage);
	cv::waitKey();
}

Watermark_Manager::~Watermark_Manager()
{
}
