#pragma once
#include <memory>
#include <iostream>
#include <opencv2/opencv.hpp>
	
class Camera {

public:

	bool open();
	void getFrame(cv::Mat &frame);
	
protected:

	std::shared_ptr<cv::VideoCapture> _capture;
	
};
