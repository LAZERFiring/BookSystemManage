#include "Login.h"
#include "ui_Login.h"
#include "UserManage.h"
#include "User.h"
#include "SystemUi.h"
#include<QFile>
#include<QTextStream>
#include<QRegularExpression>
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_Loginbtn_clicked()
{
    auto password=ui->passWord->text();
    auto username=ui->userName->text();
    QFile file("D:\\QtCode\\QtBookSystemManage\\user.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning()<<"Open failed!";
    }
    QTextStream stream(&file);
    stream.readLine();
    while(!stream.atEnd())
    {
        auto userlist=stream.readLine().split(QRegularExpression("[ \t]+"));
        UserManage::instance()->addUser(new User(userlist[0],userlist[1],User::TypeUser(userlist[2].toInt())));
        bool isLogin=false;
        if(userlist[0]==username&&userlist[1]==password&&isLogin==false)
        {
            qInfo()<<"login success!";
            isLogin=true;
            SystemUi* SysUi=new SystemUi;
            SysUi->show();
            this->hide();
        }
    }
    for(auto user:*UserManage::instance())
    {
        qInfo()<<*user;
    }
}

