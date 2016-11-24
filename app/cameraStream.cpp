#include <camera/Camera.hpp>

int main(int argc, char ** argv) {

	Camera camera;
	camera.open();
	cv::Mat frame;
	
	for (;;) {
		camera.getFrame(frame);
		cv::imshow("camera stream", frame);
		cv::waitKey(1);
	}
		
	return 0;
}
