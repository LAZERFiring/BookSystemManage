#include "ReaderManage.h"

ReaderManage::ReaderManage()
{

}

ReaderManage *ReaderManage::instanceOfReadermanage()
{
    static ReaderManage* ins = nullptr;
    if (!ins)
    {
        ins = new ReaderManage;
        return ins;
    }
    else
    {
        return ins;
    }
}
