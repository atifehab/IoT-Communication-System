/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Real_Time_Monitor;
    QLabel *temperatureLabel;
    QLabel *ledStatusLabel;
    QProgressBar *temperatureMeter;
    QWidget *Historical_Analysis;
    QVBoxLayout *verticalLayout_chart;
    QWidget *chartContainer;
    QWidget *Configuration;
    QLabel *Threshold;
    QSpinBox *thresholdSpinBox;
    QPushButton *applyThresholdButton;
    QLabel *Protocol;
    QComboBox *protocolComboBox;
    QWidget *Quick_Access;
    QPushButton *facebookButton;
    QPushButton *linkedinButton;
    QPushButton *instagramButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(815, 573);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-image: url(:/Background.jpg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"    border-image: url(:/Background.jpg) 0 0 0 0 stretch stretch;\n"
"}"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 90, 641, 401));
        QFont font;
        font.setPointSize(11);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    background-image: url(:/Background.jpg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}"));
        Real_Time_Monitor = new QWidget();
        Real_Time_Monitor->setObjectName("Real_Time_Monitor");
        temperatureLabel = new QLabel(Real_Time_Monitor);
        temperatureLabel->setObjectName("temperatureLabel");
        temperatureLabel->setGeometry(QRect(10, 60, 201, 31));
        QFont font1;
        font1.setPointSize(17);
        temperatureLabel->setFont(font1);
        ledStatusLabel = new QLabel(Real_Time_Monitor);
        ledStatusLabel->setObjectName("ledStatusLabel");
        ledStatusLabel->setGeometry(QRect(10, 160, 191, 31));
        ledStatusLabel->setFont(font1);
        temperatureMeter = new QProgressBar(Real_Time_Monitor);
        temperatureMeter->setObjectName("temperatureMeter");
        temperatureMeter->setGeometry(QRect(10, 110, 401, 41));
        temperatureMeter->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"    font-size: 14pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 0, 0, 255));\n"
"    width: 20px;\n"
"}"));
        temperatureMeter->setValue(0);
        tabWidget->addTab(Real_Time_Monitor, QString());
        Historical_Analysis = new QWidget();
        Historical_Analysis->setObjectName("Historical_Analysis");
        verticalLayout_chart = new QVBoxLayout(Historical_Analysis);
        verticalLayout_chart->setObjectName("verticalLayout_chart");
        chartContainer = new QWidget(Historical_Analysis);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setMinimumSize(QSize(0, 0));

        verticalLayout_chart->addWidget(chartContainer);

        tabWidget->addTab(Historical_Analysis, QString());
        Configuration = new QWidget();
        Configuration->setObjectName("Configuration");
        Configuration->setLayoutDirection(Qt::LeftToRight);
        Threshold = new QLabel(Configuration);
        Threshold->setObjectName("Threshold");
        Threshold->setGeometry(QRect(10, 110, 111, 18));
        Threshold->setFont(font1);
        thresholdSpinBox = new QSpinBox(Configuration);
        thresholdSpinBox->setObjectName("thresholdSpinBox");
        thresholdSpinBox->setGeometry(QRect(130, 110, 48, 23));
        thresholdSpinBox->setMinimumSize(QSize(48, 23));
        thresholdSpinBox->setMaximumSize(QSize(48, 23));
        thresholdSpinBox->setSizeIncrement(QSize(48, 27));
        thresholdSpinBox->setBaseSize(QSize(48, 27));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        thresholdSpinBox->setFont(font2);
        thresholdSpinBox->setMinimum(0);
        thresholdSpinBox->setMaximum(100);
        applyThresholdButton = new QPushButton(Configuration);
        applyThresholdButton->setObjectName("applyThresholdButton");
        applyThresholdButton->setGeometry(QRect(670, 530, 121, 26));
        Protocol = new QLabel(Configuration);
        Protocol->setObjectName("Protocol");
        Protocol->setGeometry(QRect(10, 10, 111, 18));
        Protocol->setFont(font1);
        protocolComboBox = new QComboBox(Configuration);
        protocolComboBox->addItem(QString());
        protocolComboBox->addItem(QString());
        protocolComboBox->addItem(QString());
        protocolComboBox->setObjectName("protocolComboBox");
        protocolComboBox->setGeometry(QRect(120, 10, 71, 21));
        protocolComboBox->setFont(font);
        tabWidget->addTab(Configuration, QString());
        Quick_Access = new QWidget();
        Quick_Access->setObjectName("Quick_Access");
        facebookButton = new QPushButton(Quick_Access);
        facebookButton->setObjectName("facebookButton");
        facebookButton->setGeometry(QRect(140, 100, 71, 61));
        facebookButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1877F2;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #145DBF; \n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #0F3D91;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/facebook-app-symbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        facebookButton->setIcon(icon);
        facebookButton->setIconSize(QSize(48, 48));
        linkedinButton = new QPushButton(Quick_Access);
        linkedinButton->setObjectName("linkedinButton");
        linkedinButton->setGeometry(QRect(410, 100, 71, 61));
        linkedinButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0077B5;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #005983;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #00435A;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/linkedin.png"), QSize(), QIcon::Normal, QIcon::Off);
        linkedinButton->setIcon(icon1);
        linkedinButton->setIconSize(QSize(48, 48));
        instagramButton = new QPushButton(Quick_Access);
        instagramButton->setObjectName("instagramButton");
        instagramButton->setGeometry(QRect(280, 210, 71, 61));
        instagramButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #E1306C;\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding-left: 8px;\n"
"    padding-right: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #C1275D;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #A11D4F;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/instagram.png"), QSize(), QIcon::Normal, QIcon::Off);
        instagramButton->setIcon(icon2);
        instagramButton->setIconSize(QSize(48, 48));
        tabWidget->addTab(Quick_Access, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        protocolComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        temperatureLabel->setText(QCoreApplication::translate("MainWindow", "Temperature: -- \302\260C", nullptr));
        ledStatusLabel->setText(QCoreApplication::translate("MainWindow", "LED Status: OFF", nullptr));
        temperatureMeter->setFormat(QCoreApplication::translate("MainWindow", "%v \302\260C", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Real_Time_Monitor), QCoreApplication::translate("MainWindow", "Real Time Monitor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Historical_Analysis), QCoreApplication::translate("MainWindow", "Historical Analysis", nullptr));
        Threshold->setText(QCoreApplication::translate("MainWindow", "Threshold:", nullptr));
        applyThresholdButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        Protocol->setText(QCoreApplication::translate("MainWindow", "Protocol:", nullptr));
        protocolComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Select", nullptr));
        protocolComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "TCP", nullptr));
        protocolComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "UDP", nullptr));

        protocolComboBox->setCurrentText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Configuration), QCoreApplication::translate("MainWindow", "Configuration", nullptr));
        facebookButton->setText(QString());
        linkedinButton->setText(QString());
        instagramButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Quick_Access), QCoreApplication::translate("MainWindow", "Quick Access", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
