#ifndef USERMANAGE_H
#define USERMANAGE_H
#include<QList>
class User;
class UserManage
{
public:
    using iterator=QList<User*>::iterator;
    inline iterator begin()
    {
        return userlist.begin();
    }
    inline iterator end()
    {
        return userlist.end();
    }
    static UserManage* instance();
    void addUser(User* user);
    void deleteUser(int i);
    ~UserManage();

public:
    UserManage(){}
    QList<User*> userlist;
};

#endif // USERMANAGE_H
