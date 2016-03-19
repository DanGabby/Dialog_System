#ifndef SIMPLESNO_H
#define SIMPLESNO_H
#include "semnetobj.h"

class SimpleSNO : public SemNetObj
{
public:
    SimpleSNO(QString q, QList<QString> a);
    void Execute(SignalSender *signalSender);
public:
    // данные:
    QString question;
    QList<QString> answers;
};

#endif // SIMPLESNO_H
