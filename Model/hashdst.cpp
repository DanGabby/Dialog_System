#include "hashdst.h"

HashDST::HashDST()
{}

SemNetObj *HashDST::Value(QString key)
{
    return table.value(key);
}

void HashDST::Init()
{
    //ТЕСТ
    QString q;
    QList<QString> a;
    q = "Zarabotalo?";
    a.append("Da");
    a.append("Net");
    table.insert("dialog start",new SimpleSNO(q,a));
    q = "Dovolen?";
    a.clear();
    a.append("Net");
    table.insert("Zarabotalo? Da",new SimpleSNO(q,a));
    table.insert("Dovolen? Net",new DialogEndSNO);
}

