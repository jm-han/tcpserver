#include <QDebug>
#include "camerathread.h"
#include <QByteArray>


camerathread::camerathread()
{
    sprintf(videodevice,"/dev/video0");
    videoIn = (struct vdIn *) calloc(1, sizeof(struct vdIn));
    if (init_videoIn(videoIn, videodevice, width, height, fps, format,grabmethod, avifilename) < 0)
        qDebug()<<"Camera not open!!";
}


camerathread::~camerathread()
{
    qDebug()<<Q_FUNC_INFO;
    free(videoIn);
}


void camerathread::run()
{
    unsigned char* pData = new unsigned char[videoIn->width * videoIn->height * 4];
    int i = 0;
    forever
    {
        qDebug() << i;
        unsigned long ulData = uvcGrabMJPEG(videoIn, pData);  //videoin 에서 mjpeg data 를 읽어와서 pData 에 저장하고 그 크기를 리턴해서 ulData 에 저장한다
        //usleep(100);  // delay
        QByteArray array((char *)pData,(int )ulData);
        sendData(0,array);
        qDebug() << "ulData : " << ulData;
    }
    delete [] pData;
}
