#ifndef DIALOGWORKER_H
#define DIALOGWORKER_H
#include "semnetobj.h"
#include "hashtable.h"
class DialogWorker
{
public:
    DialogWorker(){}
    SemNetObj *Next(HashTable *storage, string query)
    {
        SemNetObj *obj = storage->GetByKey(query);
        return obj;
    }
};

#endif // DIALOGWORKER_H
