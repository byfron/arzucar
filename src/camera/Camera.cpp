#include "Camera.hpp"

bool Camera::open() {

	_capture = std::make_shared<cv::VideoCapture>(0);
	if (!_capture->isOpened()) {
		return false;
	}
	return true;		
}

void Camera::getFrame(cv::Mat &frame) {

	(*_capture) >> frame;

}
