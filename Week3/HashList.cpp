#include "List.h"

class HashList {
private:
    List hash_table;
    int mod;
public:

    HashList(int mod): mod {mod}, hash_table {mod} {

    }

    int hash_function(int key) {
        return key % mod;
    }

    void insert(int key, int value) {
        if (hash_table.get_length() == mod) return;
        int hash = hash_function(key);

        while (hash_table.get_value(hash) != -1) {
                hash = (hash + 1) % mod;
        }

        Cell new_cell {key, value};
        hash_table.set_cell(new_cell, hash);
    }

    int search(int key) {
        int hash = hash_function(key);

        int temp = hash;
        while (hash_table.get_key(hash) != -1) {
            if (hash_table.get_key(hash) == key) return hash_table.get_value(hash);
            hash = (hash + 1) % mod;
            if (temp == hash) break;; 
        }

        return -1;
    }

    int remove(int key) {
        int hash = hash_function(key);

        int temp = hash;
        while (hash_table.get_key(hash) != -1) {
            if (hash_table.get_key(hash) == key) return hash_table.remove_cell(hash);
            hash = (hash + 1) % mod;
            if (temp == hash) break;
        }

        return -1;
    }

    bool containsKey(int key) {
        return search(key) != -1;
    }

    bool isEmpty() {
        return hash_table.get_length() == 0;
    }

    int size() {
        return hash_table.get_length();
    }

}; 