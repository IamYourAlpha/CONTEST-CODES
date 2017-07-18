using namespace std;
#include<bits/stdc++.h>
map<string,string> mp;

int main() {
string eng,foren;
char inp[1000];
char *ptr;
 //freopen("input.txt","r",stdin);

    while(gets(inp)) {
        if(strlen(inp)==0) break;
        ptr = strtok(inp, " ");
        eng = ptr;
        ptr = strtok(NULL,"");
        foren = ptr;
        mp[foren] = eng;
        cout << "hello" <<endl;
    }
    cout << "hello middle" << endl;

    while(gets(inp)) {
      cout << "hello" <<endl;
        foren = inp;
        if(mp[foren].length() == 0) cout <<"eh" << endl;
        else cout << mp[foren].c_str() << endl;
    }
    return 0;
}
