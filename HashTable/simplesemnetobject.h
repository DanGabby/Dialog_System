#ifndef SIMPLESEMNETOBJ_H
#define SIMPLESEMNETOBJ_H
#define MAX_ANSWERS_NUMBER 5
#include "semnetobj.h"

class SimpleSemNetObj : public SemNetObj
{
public:
    SimpleSemNetObj(string q, string a[]);
    void Execute(DataSender *dataSender);
public:
    string question;
    string answers[MAX_ANSWERS_NUMBER];    
};

#endif // SIMPLESEMNETOBJ_H
