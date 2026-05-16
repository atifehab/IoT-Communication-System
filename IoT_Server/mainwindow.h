#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>

#include "Socket.h"
#include "TCPSocket.h"
#include "UDPSocket.h"
#include "ServerChannel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Socket* socket;
    ServerChannel* channel;

    QTimer timer;

    int currentThreshold;
    int previousThreshold;

    int currentTemperature;
    bool clientConnected;
    bool getTemp = false;

    QLineSeries* series;

    void setupChart();
    void updateLEDStatus();

private slots:
    void onTimerTimeout();
};
#endif // MAINWINDOW_H
