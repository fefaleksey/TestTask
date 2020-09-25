#ifndef TESTTASK_LIST_H
#define TESTTASK_LIST_H

#include <string>

struct ListNode {
    ListNode *      prev;
    ListNode *      next;
    ListNode *      rand; // указатель на произвольный элемент данного списка, либо NULL
    std::string     data;
};

class List {
public:
    void Serialize   (FILE * file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
    void Deserialize (FILE * file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
private:
    ListNode *      head = nullptr;
    ListNode *      tail= nullptr;
    int             count = 0;
};

#endif // TESTTASK_LIST_H