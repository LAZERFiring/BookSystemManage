#include "UserManageWidget.h"
#include "User.h"
#include "UserManage.h"
#include <QTableView>
#include <QStandardItemModel>

UserManageWidget::UserManageWidget(QWidget *parent)
    :QWidget(parent)
    ,tabelview(new QTableView(this))
{
    init();
}

UserManageWidget *UserManageWidget::instance()
{
    static UserManageWidget* ins = nullptr;
    if (!ins)
    {
        ins = new UserManageWidget;
        return ins;
    }
    else
    {
        return ins;
    }
}

void UserManageWidget::init()
{
    auto model=new QStandardItemModel(this);
    tabelview->setModel(model);
    for(User* user:*UserManage::instance())
    {
        model->appendRow({new QStandardItem(user->username_),new QStandardItem(user->password_)
                          ,new QStandardItem(QString::number(user->usertype))});
    }
    tabelview->resize(777,529);
    tabelview->show();
}

void UserManageWidget::additem(const QString &username, const QString &password, int type)
{
    User* user=new User(username,password,(User::TypeUser)type);
    UserManage::instance()->addUser(user);
}

void UserManageWidget::deleteItem(int i)
{
    UserManage::instance()->deleteUser(i);
}

void UserManageWidget::freshData()
{
    auto model=new QStandardItemModel(this);
    tabelview->setModel(model);
    for(User* user:*UserManage::instance())
    {
        new QStandardItem(user->usertype);
        model->appendRow({new QStandardItem(user->username_),new QStandardItem(user->password_)
                          ,new QStandardItem(QString::number(user->usertype))});
    }
    tabelview->resize(777,529);
    tabelview->show();
}
