#ifndef HASHDST_H
#define HASHDST_H
#include "dialogstorage.h"
#include "DSObjects/dialogendsno.h"
#include "DSObjects/simplesno.h"
#include <QHash>

class HashDST : public DialogStorage
{
public:
    HashDST();

    // DialogStorage interface
public:
    SemNetObj *Value(QString key);
    void Init();
private:
    QHash<QString,SemNetObj*> table;
};

#endif // HASHDIALOGSTORAGE_H
