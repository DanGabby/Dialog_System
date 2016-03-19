#include "dialogendsno.h"

DialogEndSNO::DialogEndSNO()
{}

void DialogEndSNO::Execute(SignalSender *signalSender)
{
    emit signalSender->SIGNAL_EndOfWork();
}

