#ifndef DIALOGSTORAGE
#define DIALOGSTORAGE
#include <QString>
#include "DSObjects/semnetobj.h"
// SNO в именах классов-наследников значит: принадлежит семейству DialogStorage
class DialogStorage
{
public:
    virtual SemNetObj* Value(QString key) = 0;
    // инициализацией может быть, например, десерелизация сценария
    virtual void Init() = 0;
};
#endif // DIALOGSTORAGE

