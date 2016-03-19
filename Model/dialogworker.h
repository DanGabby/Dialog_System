#ifndef DIALOGWORKER_H
#define DIALOGWORKER_H
#include "DSObjects/semnetobj.h"
#include "hashtable.h"
#include "dialogstorage.h"
class DialogWorker
{
public:
    DialogWorker(){}
    SemNetObj *Next(DialogStorage *storage, QString query)
    {
        SemNetObj *obj = storage->Value(query);
        return obj;
    }
};

#endif // DIALOGWORKER_H
