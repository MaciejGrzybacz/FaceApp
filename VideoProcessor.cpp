#include "VideoProcessor.h"

VideoProcessor::VideoProcessor()
{
	video_path = "C:\\Users\\006ma\\Downloads\\How to Vlog.mp4";
	cap = std::make_unique<cv::VideoCapture>();
	if (!cap->open(video_path)) {
		std::cout << "Cannot open webcam";
	}
	face_detector = std::make_unique<cv::CascadeClassifier>();
	face_detector->load("C:\\Users\\006ma\\opencv\\sources\\data\\haarcascades_cuda\\haarcascade_frontalface_alt.xml");
	faces = std::vector<cv::Rect>();
	frame_counter = 0;
}

VideoProcessor::~VideoProcessor()
{
	cap->release();
}

cv::Mat VideoProcessor::capture_frame()
{
	cv::Mat frame;;
	*cap >> frame;
	while (frame.empty()) {
		cap->open(video_path);
		*cap >> frame;
		frame_counter = 0;
	}
	//frame.resize(300, 200);
	return frame;
}

cv::Mat VideoProcessor::process_frame(cv::Mat frame)
{
	face_detector->detectMultiScale(frame, faces, 1.1, 4, cv::CASCADE_SCALE_IMAGE, cv::Size(50, 50));
	for (int i = 0; i < faces.size(); i++) { //for locating the face
		cv::Mat faceROI = frame(faces[i]);//Storing face in the matrix//
		int x = faces[i].x;//Getting the initial row value of face rectangle's starting point//
		int y = faces[i].y;//Getting the initial column value of face rectangle's starting point//
		int h = y + faces[i].height;//Calculating the height of the rectangle//
		int w = x + faces[i].width;//Calculating the width of the rectangle//
		rectangle(frame, cv::Point(x, y), cv::Point(w, h), cv::Scalar(255, 0, 255), 2, 8, 0);//Drawing a rectangle using around the faces//
	}
	return frame;
}

QImage VideoProcessor::process_and_send()
{
	frame_counter++;
	cv::Mat frame = capture_frame();

	//frame = process_frame(frame);
	QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
	return qimg.rgbSwapped();
}

