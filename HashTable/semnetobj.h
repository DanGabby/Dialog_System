#ifndef SEMNETOBJ_H
#define SEMNETOBJ_H
#include "datasender.h"
// этот класс определяет семейство объектов, принадлежащих семантической сети (класс Стратегия, наверное)
class SemNetObj
{
public:
    ~SemNetObj(){}
    // объект сети при "выполнении себя", получает ссылку на контейнер для данных, куда их посылает
    virtual void Execute(DataSender *dataSender) = 0;
};

#endif // SEMNETOBJ_H
