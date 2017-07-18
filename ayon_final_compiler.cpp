#include<iostream>
#include<stdio.h>
using namespace std;

class HashInsert {
private :
    int key;
    int value;
    string type;
public :
    HashInsert(int key,string type,int value) {
        this-> key = key;
        this->type = type;
        this->value = value;
        cout << " debug 1 " << endl;
    }
    int getKey() {
        return key;
    }
    int getValue() {
        return value;
    }
};

class HashTable {

    HashInsert **table;
public :
    HashTable() {
        table  = new HashInsert*[150];
        for(int i=0; i<99; i++) table[i] = NULL;
    };

    int search__(int key,int value,string type) {
        int Hash;
        Hash  =  key%50;
        while ( table[Hash] != NULL && table[Hash]-> getKey() != key )
            Hash = ( Hash + 1 ) % 100;
        if(table[Hash] == NULL) return -1;
        else return table[Hash]->getValue();;

    }

    void save(int key,int value,string type) {
//    cout << " debug 2 " << endl;
//cout << key << " " << value << " " << endl;
        int Hash;
        Hash = key % 100;
     //   cout << Hash << endl;
    // cout << table[Hash]->getKey();
      cout << Hash << endl;
        while(table[Hash] != NULL &&  table[Hash]->getKey()!= key)
            Hash = (Hash + 1)% 100;
        if(table[Hash] != NULL) {  delete table[Hash]; new HashInsert(key,type,value); }
         else  table[Hash] = new HashInsert(key,type,value);
         return;

    }

};

int main() {
    string name,type;
    int val,n;
    int tot = 0;
    cout << " enter the number of operations" << endl;
    cin >> n;
    while(n--){
    cout << " debug 2 " << endl;
    cin >> name >> type>> val;
    for(int i=0; i<name.length(); i++) tot+= name[i];
    HashInsert *obj;
    HashTable *obk;
    obk->save(tot,val,type);
    int ans = obk->search__(tot,val,type);
    cout << ans << endl;
    }
    return 0;
}
