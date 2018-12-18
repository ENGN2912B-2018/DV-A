#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QPainter>
#include <match.h>
#include <restaurant.h>
#include <dataprocessing.h>
#include <iostream>
#include <QDebug>
#include <QWidget>
#include <myimgtest.h>

using namespace std;
QString s;
QList <class restaurant> result;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::enableSearchButton(const QString &text)
{
    ui->SearchButton->setEnabled(!text.isEmpty());
}

void MainWindow::on_SearchButton_clicked()
{
    QList<restaurant> data;
    data.clear();
    data=dataprocessing();
    QString searchs = ui->SearchEdit->text();
    s=searchs;
    if (searchs.isEmpty() == 0)
    {
        //QList<restaurant> result;
        result=match(method,searchs,data);
        QString R;

        if (result.isEmpty()==0)
        {
            Q_FOREACH(restaurant r, result)
            {
                R=R+r.getname()+":"+"\n"+r.getaddress()+"\n"+"\n";
            }
            ui->ListLabel->setText(R);
            MyImgTest* widget = new MyImgTest();
                widget->show();
            //QMessageBox::information(this, tr("list"),R)
        }
        else {
            ui->ListLabel->setText("No result.");
        }

    }
    else {
        ui->ListLabel->setText("No result.");
    }
    //show_results(searchs);

}

/*void MainWindow::show_results(QString searchs)
{
    if (searchs=="0")
    {
        QMessageBox::information(this, tr("tableModel"),tr("数据修改成功！"));
    }

}*/


/*void MainWindow::enalbeNameButton(const QString &text)
{
    recommend::match(1,text);
}*/

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NameButton_clicked()
{
    MainWindow::set_method(1);
}

void MainWindow::on_AddressButton_clicked()
{
    MainWindow::set_method(2);
}

/*void MainWindow::on_TypeButton_clicked()
{
    MainWindow::set_method(3);
}*/

/*void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);             // 创建QPainter一个对象
    QPen pen;

    //pen.setStyle(Qt::DashLine);
    //pen.setColor(Qt::red);           // 设置画笔为黄色

    painter.setPen(QPen(Qt::red,3));                // 设置画笔

    // 画多个点
    QPointF pointf[10];
    for (int i=0; i<10; ++i)
    {
        pointf[i].setX(2.0+i*10.0);
        pointf[i].setY(130.0);
    }
    painter.drawPoints(pointf, 10);

}*/
