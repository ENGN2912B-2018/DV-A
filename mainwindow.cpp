#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::enableSearchButton(const QString &text)
{
    SearchButton->setEnabled(!text.isEmpty());
}
void MainWindow::search()
{
    QString searchs = SearchEdit->text();
    if (searchs == " ")
    {
        
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

