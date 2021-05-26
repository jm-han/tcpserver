#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H
#include <QThread>
#include "v4l2uvc.h"
#include "utils.h"


class camerathread: public QThread
{
    Q_OBJECT
public:
    camerathread();
    ~camerathread() override;

protected:
    void run() override;


private:
    struct vdIn *videoIn = nullptr;

   // char *videodevice = "/dev/video0";
    char videodevice[255];


    int width = 1920;
    int height = 1080;
    int fps = 30;
    int format = V4L2_PIX_FMT_MJPEG;
    int grabmethod = 1;
    char *avifilename = nullptr;

  signals:
    void sendData(int sockDesc, const QByteArray &data);

};

#endif // CAMERATHREAD_H
