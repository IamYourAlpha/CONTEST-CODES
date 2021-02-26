/* name : intisar chowdhury
*/


using namespace std;
#include<bits/stdc++.h>

const int MAX_SIZE = 200;
int HASH__;

class ChainedEntry {
private:
    int key;
    int value;
    string type;
    ChainedEntry *next;

public:
    ChainedEntry(int key,int value,string name) : key(key),value(value),type(type),next(NULL) {}
    int return_key() {
        return key;
    }
    int return_value() {
        return value;
    }
    void SetValue(int value) {
        this->value = value;
    }
    ChainedEntry *getnext() {
        return next;
    }
    void setNext(ChainedEntry *next) {
        this->next = next;
    }
    ChainedEntry *getNext() {
        return next;
    }
};

class HashTable {
private:
    ChainedEntry **table;
public:
    HashTable() {
        table = new ChainedEntry*[MAX_SIZE];
        for(int i=0; i<MAX_SIZE; i++) table [i] = NULL;
    }
    int q(int key) {
        HASH__ = (key%MAX_SIZE);
        if( table[HASH__] == NULL ) return -999;
        else {
            ChainedEntry *point =  table [HASH__];
            while( point!=NULL && point->return_key() != key)
                point = point->getNext();
            if(point == NULL) return -999;
            else return point->return_value();
        }
    }
    int i(int key,int value,string name) {
        HASH__ = key%MAX_SIZE;
        if(table[HASH__] == NULL)
            table[HASH__] = new ChainedEntry(key,value,name);
        else {
            ChainedEntry *next =  table[HASH__];
            while( next->getNext() != NULL ) next = next->getNext();
            if(next->return_key() ==  key) next->SetValue(value);
            else  next->setNext(new ChainedEntry(key,value,name));
        }
    }

    void remove_(int key) {
        HASH__ = key%MAX_SIZE;
        if(table[HASH__] !=NULL) {
            ChainedEntry *prev = NULL;
            ChainedEntry *now = table[HASH__];
            ChainedEntry *Next;
            while(now->return_key() != key && now->getnext() != NULL) {
                prev = now;
                now = now->getNext();
            }
            if(now->return_key() == key) {
                if(prev == NULL) {
                    Next = now->getnext();
                    delete now;
                    table[HASH__] = Next;
                } else {
                    ChainedEntry *Next = now->getNext();
                    delete now;
                    prev->setNext(Next);
                }
            }
        }
    }
};

int main() {
    string VarName;
    int Value;
    string type;
    int key = 0;
    cin >> VarName >> type >> Value;
    for(int i=0; i<VarName.length(); i++) key+=VarName[i];
    ChainedEntry *ob1;
    HashTable *ob2;
    ob2->i(key,Value,type);
    return 0;
}





