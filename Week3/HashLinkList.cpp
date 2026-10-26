#include "LinkList.h"

class HashTable {
private:

    LinkList *hash_table;
    int length;
    int mod;

public:

    HashTable(int mod): mod {mod}, length {0} {
        hash_table = new LinkList [mod];
    }

    ~HashTable() {
        delete [] hash_table;
    }

    int hash_function(int value) {
        return value % mod;
    }

    void insert(int key, int value) {
        int hash = hash_function(key);

        hash_table[hash].insert_head(key, value);
        length++;
    }

    int search(int key) {
        int hash = hash_function(key);
        return hash_table[hash].search(key);
    }

    int remove(int key) {
        int hash = hash_function(key);
        int index = hash_table[hash].get_pos(key);
        if (index == -1) return -1;
        
        length--;
        return hash_table[hash].remove(index);
    }

    bool containsKey(int key) {
        int hash = hash_function(key);
        if (hash_table[hash].search(key) == -1)    return false;
        return true;
    }

    bool isEmpty() {
        return length == 0;
    }

    int size() {
        return length;
    }

};