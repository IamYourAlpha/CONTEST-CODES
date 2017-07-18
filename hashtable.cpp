using namespace std;
# include <bit/stdc++.h>



typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vector< vector<char> > > vvi;

string input;
int d_sz = 0;

struct table {
    int value;
    string str;
    int key;
} hashTable[20000];

bool taken[100000];
map < string, int > my_hash;

void HashIt(string demo) {
    int tot = 0;
    for(int i=0; i<demo.length(); i++) tot+=demo[i];
     d_sz++;
     tot = tot%d_sz;

    if(!taken[tot]) {
        hashTable[tot].str = demo;
        hashTable[tot].key = tot;
        taken[tot] = true;

    } else if(taken[tot]) {
        for(int i=tot; i>0; i--) {
            if(!taken[i]) {
                hashTable[i].str = demo;
                hashTable[i].key = i;
                taken[i] = true;
            }
        }
    }
}

void reset_My_hash() {
    for(int i=0; i<1000; i++) {
        taken[i] = false;
        hashTable[i].str = '\0' ;
        hashTable[i].key = 0;
        hashTable[i].value = 0;
    }
}

int main() {
 int len;
    reset_My_hash();
    cin >> len;
    for(int i=0; i<len; i++) {
        string demo;
        cin >> demo;
        HashIt(demo);
        }
    for(int i=0; i<10000; i++)  if(hashTable[i].key !=0) cout<< hashTable[i].str << " : " << hashTable[i].key << endl;
    //for(int i=0; i<100; i++) cout << hashTable[i].str << " : " << hashTable[i].key << endl;
    return 0;
}

