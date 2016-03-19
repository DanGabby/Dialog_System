#ifndef PRESENTER_H
#define PRESENTER_H
#include <QObject>
#include "View/view.h"
#include "Model/model.h"
// после перехода на систему сигнал-слотов, презентер стал таким тонким, что я об него чуть не порезался
// бизнес-логику размазало по всей программе (может перетащить всю логику в презентер?)
class Presenter
{
public:    
    Presenter(){}
    ~Presenter(){}
    Presenter(View *view, Model *model);
    // нужны ли проверки на "удалось ли создать связь"?
    void ProvideConnections();
private:
    View* view;
    Model* model;
};

#endif // PRESENTER_H
