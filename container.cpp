using namespace std;
#include<bits/stdc++.h>

stack<char>st;
vector < stack<char> > vec;
char str[2000];

int PutContainer(int index) {
    for(int i=0; i<vec.size(); i++) {
        if(str[index] <= vec[i].top()) {
            vec[i].push(str[index]);
           // cout << str[index] << endl;
            return 0;
        }
    }
    vec.push_back(st);
    vec[vec.size()-1].push(str[index]);
    return 1;
}

int main() {
    int k =0;
    while(gets(str)) {
        if(!strcmp(str,"end")) return 0;
        int tot = 0;
        for(int i=0; i<strlen(str); i++)
            tot+=PutContainer(i);
        printf("Case %d: %d\n",++k,tot);
        vec.clear();
    }
    return 0;
}
