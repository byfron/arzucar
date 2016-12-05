#pragma once

#include "Marker.hpp"
#include <vector>
#include <opencv2/opencv.hpp>

class MarkerDetector {

public:
	MarkerDetector();

	std::vector<Marker> detect(const cv::Mat & image) const;	

};
