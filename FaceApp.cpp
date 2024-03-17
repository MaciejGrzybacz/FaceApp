#include "FaceApp.h"
#include <qmediaplayer.h>
#include <QVideoWidget>
#include <qlabel.h>
#include<qtimer.h>

FaceApp::FaceApp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::FaceApp()), proc(new VideoProcessor())
{
    ui->setupUi(this);
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &FaceApp::show_frame);
    timer->start(40); 
}

FaceApp::~FaceApp()
{}

void FaceApp::start_video()
{
   // QMediaPlayer* player = new QMediaPlayer;
   // player->setSource((QUrl::fromLocalFile("C:\\Users\\006ma\\Downloads\\1118483_Microscopic_Microbe_Macro_3840x2160.mp4")));
   // player->setVideoOutput(ui->vviewer);
   // player->play();
}

void FaceApp::show_frame() {
    QImage img = proc->process_and_send();
    ui->fviewer->setPixmap(QPixmap::fromImage(img));
    ui->fviewer->setScaledContents(true);
}