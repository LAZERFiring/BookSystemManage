#ifndef USER_H
#define USER_H

#include<QString>
#include<QDebug>
class User
{
public:
    enum TypeUser
    {
        SysAdmin,
        BookAdmin,
        Reader
    };
    User(const QString& username,const QString& password,User::TypeUser type);
    friend QDebug operator<<(QDebug out,const User& user);
public:
    QString username_;
    QString password_;
    TypeUser usertype;
};

#endif // USER_H
