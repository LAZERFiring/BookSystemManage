#ifndef USERMANAGEWIDGET_H
#define USERMANAGEWIDGET_H

#include<QWidget>
#include<QTableView>
#include<QTabWidget>
class UserManageWidget:public QWidget
{
public:
    UserManageWidget(QWidget* parent=nullptr);
    static UserManageWidget *instance();
    void init();
    void additem(const QString& username,const QString& password,int type);
    void deleteItem(int i);
    void freshData();
private:
    QTableView* tabelview=nullptr;
};

#endif // USERMANAGEWIDGET_H
