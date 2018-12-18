#include "MyImgTest.h"
#include <QPainter>
#include <dataprocessing.h>
#include <QPointF>
#include <match.h>
#include <mainwindow.h>
#include "ui_mainwindow.h"
#include <qdebug.h>
//QString MainWindow::s;
//extern QString s;
MyImgTest::MyImgTest(QWidget* parent) : QWidget(parent)
{
    setFixedSize(591,741); //固定大小
    setWindowTitle("List");
    setStyleSheet("image:url(:/map.jpg)");
}
MyImgTest::~MyImgTest()
{

}
void MyImgTest::paintEvent(QPaintEvent *)
{
    QPainter painter(this);             //
    QPen pen;

    //pen.setStyle(Qt::DashLine);
    //pen.setColor(Qt::red);           //
    int n=result.size();
    //QPointF pointf[n];
    painter.setPen(QPen(Qt::red,5));

    Q_FOREACH(restaurant r, result)
    {
        int y=int((r.getlongitude()+71.418752)/(0.028501)*591);
        int x=int((r.getlatitude()-41.810989)/(0.02651)*741);
        qDebug()<<x<<endl;
        painter.drawPoint(x,y);
    }

    /*painter.setPen(QPen(Qt::red,5));                //

    // 画多个点
    QPointF pointf[10];
    for (int i=0; i<10; ++i)
    {
        pointf[i].setX(2.0+i*10.0);
        pointf[i].setY(130.0);
    }
    painter.drawPoints(pointf, 10);*/

}
