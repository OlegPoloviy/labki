#ifndef HASH_H
#define HASH_H

#include <string>

class Hash {
public:
    Hash(int size);
    ~Hash();

    void HashInsert(int key);
    std::string HashSearch(int key);
    void HashDelete(int key);
    void HashShow();

private:
    int* table;
    int size;
};

#endif