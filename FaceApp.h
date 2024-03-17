#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FaceApp.h"
#include "videoProcessor.h"

class FaceApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit FaceApp(QWidget *parent = nullptr);

    ~FaceApp();

    void start_video();

    void show_frame();

private:
    Ui::FaceApp* ui;
    VideoProcessor* proc;
};
