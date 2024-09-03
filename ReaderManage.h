#ifndef READERMANAGE_H
#define READERMANAGE_H

#include"Reader.h"
#include<QList>
class ReaderManage
{
public:

    using iterator=QList<Reader*>::Iterator;
    inline iterator begin()
    {
        return readerlist.begin();
    }
    inline iterator end()
    {
        return readerlist.end();
    }

    ReaderManage();

    void init();
    static ReaderManage* instanceOfReadermanage();
public:
    QList<Reader*> readerlist;
};

#endif // READERMANAGE_H
