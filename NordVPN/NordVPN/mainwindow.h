#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QDebug>
#include <QProcess>
#include <sstream>
#include <vector>
#include <map>
#include <QScrollBar>


#define     GET_COUNTRIES        0
#define     LOGIN                1
#define     CONNECT              2
#define     DISCONNECT           3
#define     LOGOUT               4
#define     ACCOUNT              5
#define     IDLE                 6


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void countryChanged(int index);
    void connectClick();
    void loginClick();
    void readOutput(int statuscode);
private:
    Ui::MainWindow *ui;
    QStringList splitString(std::string str, char delimiter);
    int state;
    std::string str;
    std::string country;
    std::vector<int> states;
    std::map<int,QProcess*> processes;

};
#endif // MAINWINDOW_H
