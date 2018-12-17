#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "dataprocessing.h"

QList<class restaurant> dataprocessing()
{
    QList<class restaurant> data;
    QFile csvFile("C:/Users/CHARLIE LIU/Documents/WeChat Files/liuxingcai484980/Files/window(2)/window/restaurant.csv");
    QStringList CSVList;
    CSVList.clear();
    if (csvFile.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&csvFile);
        while (!stream.atEnd())
        {
            CSVList.push_back(stream.readLine());
        }
        csvFile.close();
    }

    int i=0;
    Q_FOREACH(QString str, CSVList)
    {
        //qDebug() << str<<"\n";
        QStringList string;
        string  = str.split(";");
        QString _name = string[0];
        double _latitude = string[1].toDouble();
        double _longitude = string[2].toDouble();
        double _stars = string[3].toDouble();
        int _review_count = string[4].toInt();
        QString _address = string[5];
        restaurant r = restaurant(_name,_latitude,_longitude,_stars,_review_count,_address);
        data.append(r);

        i++;
        //qDebug() << i << _name <<" "<<_address<<endl;
    }
    return data;

}
