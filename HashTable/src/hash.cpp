#include "hash.h"

// LOOK FOR THE COMMENTS IN THE .H 
// TO UNDERSTAND WHAT EACH FUNCTION MUST DO

Hash::Hash(int tablesize, int (*hf) (std::string) ) {
 // CONSTRUTOR

    _table.resize(tablesize);
    _hash_func = hf;


}

int Hash::add(std::string str, int &collisions) {

    int pos = hash(str);
    if (contains(str, collisions)) {
        return 0;
    }
    else{
        _table[pos].push_front(str);
        return 1;
    }
    
}//add

int Hash::remove(std::string str, int &collisions) { 
    
    if (contains(str, collisions) == 1) {
        int key = hash(str);
        _table[key].remove(str);
        return 1;
    }
    else
        return 0;
    
}//remove


int Hash::hash(std::string str) {

    int key = 0;
    for (char c : str) {
        key += c;
    }
    key = key % _table.size();
    
    return key;
    
}//hash
    
int Hash::contains(std::string str, int &collisions) {

    int key = hash(str);
    collisions = 0;
    for (std::forward_list<std::string>::iterator it = _table[key].begin(); it != _table[key].end(); it++) {
        collisions += 1;
        if (*it == str)
            return 1;
    }

    return 0;
    
}//contains


int Hash::worst_case() {

    int w = 0;

    for(int i = 0; i <= _table.size() -1 ; i++) {
        if( std::distance(_table[i].begin(), _table[i].end()) > w)
            w = std::distance(_table[i].begin(), _table[i].end());
    }

    return w;
    
}//worst_case

int Hash::size() {

    int totalSize = 0;
    for(int i = 0; i <= _table.size() -1 ; i++) {
        int listSize = std::distance(_table[i].begin(), _table[i].end());
        totalSize += listSize;
    }

    return totalSize;
    
}//size

