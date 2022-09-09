#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->countryListView,SIGNAL(currentRowChanged(int)),this,SLOT(countryChanged(int)));

    connect(ui->btnConnect,SIGNAL(clicked()),this,SLOT(connectClick()));
    connect(ui->btnLogin,SIGNAL(clicked()),this,SLOT(loginClick()));

    states.push_back(GET_COUNTRIES);
    states.push_back(LOGIN);
    states.push_back(CONNECT);
    states.push_back(DISCONNECT);
    states.push_back(LOGOUT);
    states.push_back(ACCOUNT);
    states.push_back(IDLE);


    for(int i=0;i<states.size();i++)
    {
        processes.insert({states.at(i), new QProcess(this)});
        connect(processes[states.at(i)],SIGNAL(finished(int)),this,SLOT(readOutput(int)));

    }

    state = GET_COUNTRIES;
    processes[state]->start("nordvpn",QStringList() << "countries");


    ui->textEdit->ensureCursorVisible();


    //ui->textEdit->setTextInteractionFlags(ui->textEdit->textInteractionFlags() | Qt::LinksAccessibleByMouse | Qt::TextBrowserInteraction);
}

void MainWindow::readOutput(int statuscode)
{
    QByteArray result =  processes[state]->readAllStandardOutput();

    str = result.toStdString();

    QStringList tmp =splitString(str,'\r');
    QString temp = "";//str.c_str();

    for(int i=0;i<tmp.size();i++)
    {
        if(tmp.at(i).size()>3 && !tmp.at(i).contains("New feature"))
            temp += tmp.at(i) + '\n';
    }


    if(state == GET_COUNTRIES)
    {
        QStringList raw = splitString(str,'-');

        ui->countryListView->addItems(splitString(raw.at(raw.size()-1).simplified().remove(' ').toStdString(),','));

        ui->countryListView->setCurrentRow(19);

        state = ACCOUNT;
        processes[state]->start("nordvpn",QStringList() << "account");
        processes[state]->waitForFinished();
    }
    else if(state == ACCOUNT)
    {
        ui->textEdit->insertPlainText(temp);
        state = IDLE;
    }
    else if(state == LOGIN)
    {
        ui->textEdit->insertPlainText(temp);
        state = IDLE;
    }
    else if(state == CONNECT)
    {
         ui->textEdit->insertPlainText(temp);
         if(temp.contains("connected"))
         {
               ui->btnConnect->setText("Disconnect");
         }
         state = IDLE;

    }
    else if(state == DISCONNECT)
    {
        ui->textEdit->insertPlainText(temp);
        if(temp.contains("disconnected"))
            ui->btnConnect->setText("Connect");
    }
    else if(state == IDLE)
    {
    }

    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());


}

MainWindow::~MainWindow()
{
    //process->start("nordvpn",QStringList() << "disconnect");
    qDebug() << "destructor";
    //process->terminate();
    delete ui;
}


void MainWindow::countryChanged(int index)
{
    country = ui->countryListView->item(index)->text().simplified().remove(' ').toStdString();
}

void MainWindow::loginClick()
{
    state = LOGIN;
    processes[state]->start("nordvpn",QStringList() << "login");
    processes[state]->waitForFinished();
}

void MainWindow::connectClick()
{

    if(ui->btnConnect->text() == "Connect")
    {
        state = CONNECT;
        processes[state]->start("nordvpn",QStringList() << "connect" << country.c_str());
    }
    else
    {
        state = DISCONNECT;
        processes[state]->start("nordvpn",QStringList() << "disconnect");
    }

}

QStringList MainWindow::splitString(std::string str, char delimiter)
{
    QStringList temp;

    std::stringstream sstream(str);
    std::vector<std::string> res;

    while (sstream.good()) {

      std::string substr;
      getline(sstream, substr, delimiter); //get first string delimited by comma
      res.push_back(substr);

    }

    for(int i=0; i<res.size();i++)
        temp << res.at(i).c_str();

    return temp;
}
