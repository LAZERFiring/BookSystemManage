#include "ReaderManageWidget.h"
#include "ReaderManage.h"
#include <QStandardItemModel>

ReaderManageWidget::ReaderManageWidget(QWidget *parent)
    :QWidget(parent)
{
    initAndShow();
}

ReaderManageWidget *ReaderManageWidget::instanceOfReaderManageWidget()
{
    static ReaderManageWidget* ins = nullptr;
    if (!ins)
    {
        ins = new ReaderManageWidget;
        return ins;
    }
    else
    {
        return ins;
    }
}

void ReaderManageWidget::initAndShow()
{
    QStandardItemModel* model=new QStandardItemModel;
    tableView=new QTableView(this);
    tableView->setModel(model);
    model->appendRow({new QStandardItem(QString("读者名")),new QStandardItem(QString("读者号")),new QStandardItem(QString("借书")),new QStandardItem(QString("借书日期")),new QStandardItem(QString("还书日期"))});
    for(auto Reader:*ReaderManage::instanceOfReadermanage())
    {
        model->appendRow({new QStandardItem(Reader->_name),
                         new QStandardItem(Reader->_number),
                         new QStandardItem(Reader->_BorrowBook),
                         new QStandardItem(Reader->_BorrowDate),
                         new QStandardItem(Reader->_ReturnDate)});
    }
    tableView->resize(777,529);
    tableView->show();
}

void ReaderManageWidget::freashData()
{
    QStandardItemModel* model=new QStandardItemModel;
    tableView=new QTableView(this);
    tableView->setModel(model);
    model->appendRow({new QStandardItem(QString("读者名")),new QStandardItem(QString("读者号")),new QStandardItem(QString("借书")),new QStandardItem(QString("借书日期")),new QStandardItem(QString("还书日期"))});
    for(auto Reader:*ReaderManage::instanceOfReadermanage())
    {
        model->appendRow({new QStandardItem(Reader->_name),
                         new QStandardItem(Reader->_number),
                         new QStandardItem(Reader->_BorrowBook),
                         new QStandardItem(Reader->_BorrowDate),
                         new QStandardItem(Reader->_ReturnDate)});
    }
    tableView->resize(777,529);
    tableView->show();
}
