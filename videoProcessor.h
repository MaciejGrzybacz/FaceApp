#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <QImage>
#include <memory>


class VideoProcessor {
	std::unique_ptr<cv::VideoCapture> cap;
	std::unique_ptr<cv::CascadeClassifier> face_detector;
	std::vector<cv::Rect> faces;
	std::string video_path;
	int frame_counter;
public:
	VideoProcessor();

	~VideoProcessor();

private:
	cv::Mat capture_frame();
	cv::Mat process_frame(cv::Mat);
public:
	QImage process_and_send();
	
};