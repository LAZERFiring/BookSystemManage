#ifndef READER_H
#define READER_H

#include<QString>
class Reader
{
public:
    Reader();
    Reader(const QString& name,const QString& number,const QString& BorrowBook,const QString& BorrowDate,const QString& ReturnDate);
public:
    QString _name;
    QString _number;
    QString _BorrowBook;
    QString _BorrowDate;
    QString _ReturnDate;
};

#endif // READER_H
