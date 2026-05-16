#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QThread>
#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socket(nullptr)
    , channel(nullptr)
    , currentThreshold(30)
    , previousThreshold(-1)
    , currentTemperature(0)
    , clientConnected(false)
{
    ui->setupUi(this);
    connect(ui->facebookButton, &QPushButton::clicked, this, [](){
        QDesktopServices::openUrl(QUrl("https://www.facebook.com/edgesfortraining"));
    });

    connect(ui->instagramButton, &QPushButton::clicked, this, [](){
        QDesktopServices::openUrl(QUrl("https://www.instagram.com/edgesfortraining"));
    });

    connect(ui->linkedinButton, &QPushButton::clicked, this, [](){
        QDesktopServices::openUrl(QUrl("https://www.linkedin.com/company/edges-for-training"));
    });

    ui->thresholdSpinBox->setValue(30);
    setupChart();
    connect(ui->protocolComboBox, &QComboBox::currentTextChanged, this, [this](const QString& protocol) {
        if (channel) {
            channel->stop();
            delete channel;
            channel = nullptr;
        }
        if (socket) {
            delete socket;
            socket = nullptr;
        }

        if (protocol == "TCP")
            socket = new TCPSocket();
        else if (protocol == "UDP")
            socket = new UDPSocket();
        else
            return;

        channel = new ServerChannel(socket);
        channel->start();
        clientConnected = false;
        previousThreshold = currentThreshold;
    });
    connect(&timer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
    timer.start(1000);
}

MainWindow::~MainWindow()
{
    timer.stop();
    if (channel) {
        channel->stop();
        delete channel;
    }
    if (socket)
        delete socket;
    delete ui;
}

void MainWindow::setupChart()
{
    series = new QLineSeries();

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Temperature History");

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chart->setTheme(QChart::ChartThemeLight);
    chartView->setMinimumHeight(300);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(chartView);

    ui->chartContainer->setLayout(layout);
}

void MainWindow::onTimerTimeout()
{
    if (!channel) return;

    currentThreshold = ui->thresholdSpinBox->value();

    if (!clientConnected) {
        QString response = channel->receive();
        if (response.trimmed() == "HELLO") {
            clientConnected = true;
            previousThreshold = currentThreshold;
        }
        return;
    }

    if(getTemp)
    {
        channel->send("set threshold");
        QThread::msleep(50);
        if(currentThreshold != previousThreshold)
        {
            channel->send(QString::number(currentThreshold));
            previousThreshold = currentThreshold;
            getTemp = false;
        }
    }
    else if(!getTemp)
    {
        channel->send("get Temp");
        getTemp = true;
        QString response = {};
        while(response.isEmpty() || response == "")
        {
            response = channel->receive();
        }

        if (!response.isEmpty()) {
            currentTemperature = response.toInt();

            ui->temperatureLabel->setText(
                "Temperature: " + QString::number(currentTemperature) + " °C");
            ui->temperatureMeter->setValue(currentTemperature);

            series->append(series->count(), currentTemperature);
            
            QChart* chart = series->chart();
            if (chart) {
                while (!chart->axes().isEmpty()) {
                    chart->removeAxis(chart->axes().first());
                }
                chart->createDefaultAxes();
                if (chart->axisX()) chart->axisX()->setRange(0, qMax(10.0, (double)series->count()));
                if (chart->axisY()) chart->axisY()->setRange(0, 100);
            }

            updateLEDStatus();
        }
    }
}

void MainWindow::updateLEDStatus()
{
    if(currentTemperature <= currentThreshold)
        ui->ledStatusLabel->setText("LED Status: ON");
    else
        ui->ledStatusLabel->setText("LED Status: OFF");
}
