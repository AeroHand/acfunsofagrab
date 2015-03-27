#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->passwordbuff->setEchoMode(QLineEdit::Password);
    manager = new QNetworkAccessManager(this);


    connect(manager,SIGNAL(finished(QNetworkReply*)), //关联信号和槽
    this,SLOT(replyFinished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startbutton_released()
{
    ui->startbutton->setEnabled(ui->idname->hasAcceptableInput());
    //获取输入框内用户名及密码

    QString id = ui->idname->text();
    QString pas = ui->passwordbuff->text();

    //获取http网页
    manager->get(QNetworkRequest(QUrl("http://www.acfun.tv")));

    //登出 登录

    //循环下载文章区页面数据

    //查看是否有沙发

    //发帖

    //循环


}

void MainWindow::replyFinished(QNetworkReply *reply) //当回复结束后
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    //使用 utf8 编码，这样才可以显示中文
    QString all = codec->toUnicode(reply->readAll());
    ui->textBrowser->setText(all);
    reply->deleteLater(); //最后要释放 reply 对象
}


