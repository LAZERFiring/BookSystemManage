#include "Reader.h"

Reader::Reader()
{

}

Reader::Reader(const QString &name, const QString &number, const QString &BorrowBook, const QString &BorrowDate, const QString &ReturnDate)
    :_name(name),_number(number),_BorrowBook(BorrowBook),_BorrowDate(BorrowDate),_ReturnDate(ReturnDate)
{

}
