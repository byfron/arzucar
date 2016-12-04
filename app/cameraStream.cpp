#include <camera/Camera.hpp>

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

		cv::Mat labels;
		int num_comp = cv::connectedComponents(255 - grayFrame, labels);
		std::cout << "num comp "<< num_comp << std::endl;  
		cv::normalize(labels, labels, 0, 255, cv::NORM_MINMAX, CV_8U);

	
		cv::Mat colored_labels;
		// labels.convertTo(labels, CV_32F);
		// cv::normalize(labels, labels, 0.0, 1.0, cv::NORM_MINMAX, CV_32F);
		cvtColor(labels, labels, CV_GRAY2RGB);

		cv::applyColorMap(labels, colored_labels, cv::COLORMAP_JET);
		cv::imshow("comp", colored_labels);
		cv::waitKey(1);
	}
		
	return 0;
}
