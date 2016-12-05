#include "MarkerDetector.hpp"

cv::RNG rng(12345);

MarkerDetector::MarkerDetector() {}

std::vector<Marker> MarkerDetector::detect(const cv::Mat & frame) const {

	
	cv::Mat grayFrame;
	cvtColor(frame, grayFrame, CV_RGB2GRAY);
	cv::threshold(grayFrame, grayFrame, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	cv::imshow("comp", grayFrame);
	cv::waitKey(1);

	std::vector< std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::Mat mask = grayFrame > 0;
	cv::findContours(mask, contours, hierarchy, CV_RETR_TREE,
			 CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
		
	cv::Mat labels;
	int num_comp = cv::connectedComponents(255 - grayFrame, labels);

	/// Draw contours with inner contour
	std::vector<cv::Rect> boundRect( contours.size() );
	std::vector<std::vector<cv::Point> > contours_poly( contours.size() );
	std::vector<float>radius( contours.size() );
	std::vector<cv::Point2f>center( contours.size() );

	cv::Mat drawing = cv::Mat::zeros(grayFrame.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ )
	{
		if (hierarchy[i][2] > 0) {

			float  epsilon = 0.05*arcLength(contours[i],true);
			approxPolyDP( cv::Mat(contours[i]), contours_poly[i], epsilon, true );
			boundRect[i] = boundingRect( cv::Mat(contours_poly[i]) );

			if (contours_poly[i].size() == 4)
			{
				// get bounding box
				cv::Scalar color = cv::Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
				drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, cv::Point() );
			}
		}


	}

	cv::imshow("contours", drawing);
	cv::waitKey(1);

	return std::vector<Marker>();

}
