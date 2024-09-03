#include "SystemUi.h"
#include "ui_SystemUi.h"
#include "QTreeWidgetItem"
#include "UserManageWidget.h"
#include "Reader.h"
#include "ReaderManage.h"
#include "ReaderManageWidget.h"
#include <QTabWidget>
#include <QLineEdit>
#include <QEventLoop>
#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QTableView>
#define ReaderIns ReaderManage::instanceOfReadermanage()
SystemUi::SystemUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemUi)
{
    ui->setupUi(this);
    pitem=nullptr;
    pitem=new QTreeWidgetItem(ui->treeWidget,QStringList({"图书信息管理菜单"}));

    //用户管理菜单
    auto userManageItem= new QTreeWidgetItem(QStringList({"用户管理"}),UserManage);
    {
        userManageItem->addChild(new QTreeWidgetItem(QStringList({"用户信息密码修改"}),UserInfoModiefy));
        userManageItem->addChild(new QTreeWidgetItem(QStringList({"用户信息添加"}),UserInput));
        userManageItem->addChild(new QTreeWidgetItem(QStringList({"用户信息删除"}),UserDelete));
    }
    pitem->addChild(userManageItem);

    //读者管理菜单
    auto readerManage=new QTreeWidgetItem(QStringList({"读者管理"}),ReaderManage);
    pitem->addChild(readerManage);
    readerManage->addChild(new QTreeWidgetItem(QStringList({"读者借书"}),ReaderAdd));
    readerManage->addChild(new QTreeWidgetItem(QStringList({"读者还书"}),ReaderDelete));
    readerManage->addChild(new QTreeWidgetItem(QStringList({"读者信息查询"}),ReaderSerch));


    pitem->addChild(new QTreeWidgetItem(QStringList({"图书管理"}),BookManage));
    pitem->addChild(new QTreeWidgetItem(QStringList({"图书流通管理"}),Bookcirculate));
    connect(ui->treeWidget,&QTreeWidget::itemClicked,this,&SystemUi::On_ItemClicked);
}

SystemUi::~SystemUi()
{
    delete ui;
    delete pitem;
}

void SystemUi::initAndShowUsers()
{
    tab=new QTabWidget(ui->listWidget);
    tab->resize(777,529);
    userManageWidget=UserManageWidget::instance();
    userManageWidget->freshData();
    tab->addTab(userManageWidget,"用户管理");
    tab->show();
    userManageWidget->show();
}

void SystemUi::initAndShowReaders()
{
    //Load data
    QFile file("D:\\QtCode\\QtBookSystemManage\\Reader.txt");
    if(!file.open(QIODevice::ReadWrite))
    {
        qInfo()<<"Reader.txt open failed!";
        return;
    }
    QTextStream stream(&file);
    stream.readLine();
    while(!stream.atEnd())
    {
        auto lineInfoOfReader=stream.readLine();
        auto lineInfoOfReaderLists=lineInfoOfReader.split(QRegularExpression("[ \t]+"));
        ReaderManage::instanceOfReadermanage()->readerlist.append(new Reader(
                                                                      lineInfoOfReaderLists[0],
                                                                  lineInfoOfReaderLists[1],
                lineInfoOfReaderLists[2],
                lineInfoOfReaderLists[3],
                lineInfoOfReaderLists[4]));
    }
    //Show data in the view
    tab=new QTabWidget(ui->listWidget);
    tab->resize(777,529);
    tab->addTab(ReaderManageWidget::instanceOfReaderManageWidget(),"读者管理");
    tab->show();
}

void SystemUi::inputDialog(const QString &string)
{
    QDialog dialog;
    auto layout=new QHBoxLayout;
    auto lineEdit=new QLineEdit;
    auto acceptBtn=new QPushButton("确认");

    lineEdit->setPlaceholderText(string);
    lineEdit->resize(500,30);
    layout->addWidget(lineEdit);layout->addWidget(acceptBtn);
    dialog.setWindowTitle("请输入信息");
    dialog.resize(350,30);
    dialog.setLayout(layout);

    connect(acceptBtn,&QPushButton::clicked,&dialog,&QDialog::close);
    dialog.exec();

    userInputinfo=lineEdit->text();
}

void SystemUi::On_ItemClicked(QTreeWidgetItem* item, int column)
{
    switch (item->type()) {
    case UserManage:
    {
        initAndShowUsers();
        qInfo()<<"UserManage";
    }
        break;
    case ReaderManage:
        initAndShowReaders();
        qInfo()<<"2";
        break;
    case ReaderAdd:
    {
        inputDialog("读者名/读者号/借书/借书日期/还书日期");
        if(!userInputinfo.isEmpty())
        {
            QStringList stringlist=userInputinfo.split("/");
            ReaderManage::instanceOfReadermanage()->readerlist.append(new Reader(stringlist[0],
                                                                      stringlist[1],
                    stringlist[2],
                    stringlist[3],
                    stringlist[4]));
            ReaderManageWidget::instanceOfReaderManageWidget()->freashData();
        }
    }
        break;
    case ReaderDelete:
    {
        inputDialog("请输入要要还书者/书名");
        QStringList stringlist=userInputinfo.split("/");
        if(!userInputinfo.isEmpty())
        {
            QList<Reader*>::iterator it=ReaderManage::instanceOfReadermanage()->readerlist.begin();
            while(it!=ReaderManage::instanceOfReadermanage()->readerlist.end())
            {
                if((*it)->_name==stringlist[0]&&(*it)->_BorrowBook==stringlist[1])
                {
                    it=ReaderManage::instanceOfReadermanage()->readerlist.erase(it);
                }
                else
                {
                    it++;
                }
            }
            ReaderManageWidget::instanceOfReaderManageWidget()->freashData();
        }
    }
        break;
    case ReaderSerch:
    {
        inputDialog("请输入读者名");
        if(!userInputinfo.isEmpty())
        {
            QList<Reader*> list;
            if(!userInputinfo.isEmpty())
            {
                QList<Reader*>::iterator it=ReaderIns->begin();
                while(it!=ReaderIns->end())
                {
                    if((*it)->_name==userInputinfo)
                    {
                        list.append(new Reader((*it)->_name,(*it)->_number,(*it)->_BorrowBook,(*it)->_BorrowDate,(*it)->_ReturnDate));
                        it++;
                    }
                    else
                    {
                        it++;
                    }
                }
            }
            QStandardItemModel* model=new QStandardItemModel;
            QTableView* view=new QTableView;
            view->setModel(model);
            for(auto reader:list)
            {
                model->appendRow({new QStandardItem(reader->_name),
                                  new QStandardItem(reader->_number),
                                  new QStandardItem(reader->_BorrowBook),
                                  new QStandardItem(reader->_BorrowDate),
                                  new QStandardItem(reader->_ReturnDate),});
            }
            view->resize(500,300);
            view->setWindowTitle("读者信息");
            view->show();
        }
    }
        break;
    case UserInfoModiefy:
    {
        initAndShowUsers();
        qInfo()<<"UserInfoModiefy";
    }
        break;
    case UserInput:
    {
        inputDialog("请输入要创建的用户名/密码/用户类型");
        QStringList valueList = userInputinfo.split('/');
        if(!userInputinfo.isEmpty())
        {
            auto userManageWidget=UserManageWidget::instance();
            userManageWidget->additem(valueList.value(0),valueList.value(1),valueList.value(2).toInt());
            userManageWidget->freshData();
        }
    }
        break;
    case UserDelete:
    {
        inputDialog("请输入要删除的用户编号");
        if(!userInputinfo.isEmpty())
        {
            auto userManageWidget=UserManageWidget::instance();
            userManageWidget->deleteItem(userInputinfo.toInt()-1);
            userManageWidget->freshData();
        }
    }
        break;
    }
}

