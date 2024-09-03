#ifndef READERMANAGEWIDGET_H
#define READERMANAGEWIDGET_H
#include<QWidget>
#include<QTableView>
class ReaderManageWidget: public QWidget
{
public:

    ReaderManageWidget(QWidget* parent=nullptr);
    void initAndShow();
    void freashData();
    static ReaderManageWidget* instanceOfReaderManageWidget();
private:
    QTableView* tableView;
};

#endif // READERMANAGEWIDGET_H
