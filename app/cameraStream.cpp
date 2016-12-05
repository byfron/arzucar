#include <camera/Camera.hpp>
#include <engine/MarkerDetector.hpp>

using namespace cv;



int main(int argc, char ** argv) {

	Camera camera;
	MarkerDetector detector;
	camera.open();
	cv::Mat frame;
	
	for (;;) {
		camera.getFrame(frame);

		detector.detect(frame);
		

	
		
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
