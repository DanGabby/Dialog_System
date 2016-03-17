#ifndef HTCELL_H
#define HTCELL_H
#include "semnetobj.h"
using namespace std;
// таблица работает с целочисленными ключами
//typedef int32 TKey;

class HTCell
{
public:
    HTCell(){}
    HTCell(SemNetObj* val, int key)
    {
        _val = val;
        _key = key;
    }
    int GetKey()
    {
        return _key;
    }
    SemNetObj* GetVal()
    {
        return _val;
    }

private:
    SemNetObj* _val;
    int _key;
};

#endif // HTCELL_H
