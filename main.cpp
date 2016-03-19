//#include "view.h"
#include "Presenter/presenter.h"
//#include "answerquestionobject.h"
//#include "hashtable.h"
//#include "dsysdata.h"
#include <iostream>
#include <QCoreApplication>
#include "Model/hashdst.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // инициализация
    HashDST storage;
    storage.Init();
    Model model(&storage);
    // передаём ссылку на QCoreApplication,
    // чтобы можно было QCoreApplication.exit() и выйти из цикла
    View view(&a);
    Presenter presenter(&view,&model);
    presenter.ProvideConnections();
    // запускаем систему сигналслотов
    emit view.SIGNAL_StartWork();
    return a.exec();
}
//int main()
//{
//    Model model;
//    View view;
//    Presenter presenter(&view,&model);
//    presenter.ProvideConnections();
//    view.Init();
//    view.ConsoleQuery();
//}
