#include "User.h"

User::User(const QString &username, const QString &password, TypeUser type)
    :username_(username),password_(password),usertype(type)
{

}
QDebug operator<<(QDebug out,const User& user)
{
    out<<user.username_<<" "<<user.password_<<" "<<user.usertype;
    return out;
}
