#include "UserManage.h"
#include "User.h"
#include<QDebug>
UserManage *UserManage::instance()
{
    static UserManage* ins = nullptr;
    if (!ins)
    {
        ins = new UserManage;
        return ins;
    }
    else
    {
        return ins;
    }
}

void UserManage::addUser(User* user)
{
    userlist.append(user);
}

void UserManage::deleteUser(int i)
{
    userlist.removeAt(i);
}

UserManage::~UserManage()
{
    for(auto user:*UserManage::instance())
    {
        delete user;
    }
}
