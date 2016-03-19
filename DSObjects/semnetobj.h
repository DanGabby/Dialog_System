#ifndef SEMNETOBJ_H
#define SEMNETOBJ_H
#include "Model/datasender.h"
// этот класс определяет семейство объектов, принадлежащих семантической сети (класс Стратегия, наверное)
// SNO в именах классов-наследников значит: принадлежит семейству SemNetObject
class SemNetObj
{
public:
    ~SemNetObj(){}
    // объект сети при "выполнении себя", получает ссылку на контейнер для данных, куда их посылает
    // каждый объект семейства SemNetObj знает своё предназначение, дайте ему его выполнить.
    virtual void Execute(SignalSender *signalSender) = 0;
};

#endif // SEMNETOBJ_H
