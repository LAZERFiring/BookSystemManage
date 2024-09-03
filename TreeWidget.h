#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include<QTreeWidget>
class QTreeWidgetItem;
class TreeWidget:public QTreeWidget
{
public:
    enum ManageSystem
    {
        UserManage,
        ReaderManage,
        BookManage,
        BookCirculateManage,
        QuitSystem
    };
    TreeWidget(const QString& name,TreeWidget::ManageSystem Type,QTreeWidget* parent=nullptr);
    TreeWidget();
private:

};

#endif // TREEWIDGET_H
