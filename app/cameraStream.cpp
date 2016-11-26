#include <camera/Camera.hpp>

int main(int argc, char ** argv) {

	Camera camera;
	camera.open();
	cv::Mat frame;
	
	for (;;) {
		camera.getFrame(frame);

		cv::Mat grayFrame;
		cvtColor(frame, grayFrame, CV_RGB2GRAY);
		
		cv::adaptiveThreshold(grayFrame, grayFrame, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY,11,2);
		
		cv::imshow("camera stream", grayFrame);
		cv::waitKey(1);
	}
		
	return 0;
}
