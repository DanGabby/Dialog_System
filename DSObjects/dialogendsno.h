#ifndef DIALOGENDSNO_H
#define DIALOGENDSNO_H
#include "semnetobj.h"

class DialogEndSNO : public SemNetObj
{
public:
    DialogEndSNO();

    // SemNetObj interface
public:
    void Execute(SignalSender *signalSender);
};

#endif // DIALOGENDSNO_H
