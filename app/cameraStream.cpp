#include <camera/Camera.hpp>

using namespace cv;

RNG rng(12345);


int main(int argc, char ** argv) {

	Camera camera;
	camera.open();
	cv::Mat frame;
	
	for (;;) {
		camera.getFrame(frame);

		cv::Mat grayFrame;
		cvtColor(frame, grayFrame, CV_RGB2GRAY);
		cv::threshold(grayFrame, grayFrame, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
		cv::imshow("comp", grayFrame);
		cv::waitKey(1);

		std::vector< std::vector<cv::Point> > contours;
		std::vector<cv::Vec4i> hierarchy;
		Mat mask = grayFrame > 0;
		cv::findContours(mask, contours, hierarchy, CV_RETR_TREE,
				 CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
		
		cv::Mat labels;
		int num_comp = cv::connectedComponents(255 - grayFrame, labels);

		 /// Draw contours with inner contour
		std::vector<Rect> boundRect( contours.size() );
		std::vector<std::vector<Point> > contours_poly( contours.size() );
		std::vector<float>radius( contours.size() );
		std::vector<Point2f>center( contours.size() );

		Mat drawing = Mat::zeros(grayFrame.size(), CV_8UC3 );
		for( int i = 0; i< contours.size(); i++ )
		{
			if (hierarchy[i][2] > 0) {

				float  epsilon = 0.05*arcLength(contours[i],true);
				approxPolyDP( Mat(contours[i]), contours_poly[i], epsilon, true );
				boundRect[i] = boundingRect( Mat(contours_poly[i]) );

				if (contours_poly[i].size() == 4)
				{
				// get bounding box
				Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
				drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
				}
			}


		}		

		cv::imshow("contours", drawing);
		cv::waitKey(1);
		
		// cv::Mat colored_labels;
		// // labels.convertTo(labels, CV_32F);
		// // cv::normalize(labels, labels, 0.0, 1.0, cv::NORM_MINMAX, CV_32F);
		// cvtColor(labels, labels, CV_GRAY2RGB);

		// cv::applyColorMap(labels, colored_labels, cv::COLORMAP_JET);
		// cv::imshow("comp", colored_labels);
		// cv::waitKey(1);
	}
		
	return 0;
}
