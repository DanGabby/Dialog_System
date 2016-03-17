#ifndef HASHTABLE_H
#define HASHTABLE_H
using namespace std;
// пусть хеш-ключ будет int
typedef int HashIndexType;
#include "htcell.h"
//#include "semnetobj.h"
//#include <string>
// хеш рассчитывается методом деления, поэтому рекомендованный размер таблицы — простое число
#define SIZE 31

class HashTable
{
public:    
    HashTable();
    // таблица работает с int ключами по единственному полю
    // если ключ не числовой и/или составной, происходит его преобразование в int

    // ВСТАВКА
    void Insert(SemNetObj* val, int key);
    void Insert(SemNetObj* val, string stringKey);
    // ВЫБОРКА ПО КЛЮЧУ
    SemNetObj* GetByKey(int key);
    SemNetObj* GetByKey(string stringKey);

protected:
    // множество объектов принадлежащих хеш-таблице определяется 2-мя массивами:
    HTCell values[SIZE];
    bool empty[SIZE];
    // высчитываем хеш способом деления    
    HashIndexType CalculateHash(int key);
    // при использовании хеш таблицы, пользователь выбирает свойство, которое больше подходит
    // для использования в качестве ключевого (здесь ключом является пара строк "вопрос" и "ответ")
    // "вопрос" и "ответ" нужно как-то превратить в int
    // функция, которая определяет преобразование двух строк в int:
    int KeyGen (string stringKey);
};

#endif // HASHTABLE_H
