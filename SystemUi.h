#ifndef SYSTEMUI_H
#define SYSTEMUI_H

#include <QWidget>
#include "UserManageWidget.h"
namespace Ui {
class SystemUi;
}
class QTreeWidgetItem;
class SystemUi : public QWidget
{
    Q_OBJECT

public:
    enum SelectType
    {
        //Main Menu
        UserManage,
        ReaderManage,
        BookManage,
        Bookcirculate,
        //Sub Menu of UserManage
        UserInput,
        UserInfoModiefy,
        UserDelete,
        UserShow,
        UserPasswordModiefy,
        //Sub menu of ReaderManage
        ReaderAdd,
        ReaderDelete,
        ReaderSerch,
        ReaderModify
    };
    explicit SystemUi(QWidget *parent = nullptr);
    ~SystemUi();
    void initAndShowUsers();
    void initAndShowReaders();
    void inputDialog(const QString& string);
public slots:
    void On_ItemClicked(QTreeWidgetItem* item, int column);
private:
    Ui::SystemUi *ui;
    QTreeWidgetItem* pitem;
    UserManageWidget* userManageWidget=nullptr;
    QString userInputinfo;
    QTabWidget* tab;
};

#endif // SYSTEMUI_H
