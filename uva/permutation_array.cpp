#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;


struct SS {
    int a;
    string ss;
} A[20000];

bool comp(SS x,SS y) {
    if(x.a<y.a) return true;
    else return false;
}



int main() {
    int tc;
    char s[20000];
    scanf("%d",&tc);
    getchar();
    bool space =false;
    while(tc--) {
        gets(s);
        gets(s);
        int i=0;
        char *p= strtok(s," ");
        while(p) {
            A[i].a= atoi(p);
            p= strtok(NULL," ");
            i++;
        }
        gets(s);
        p=strtok(s," ");
        i=0;
        while(p) {
            A[i].ss=p;
            p= strtok(NULL," ");
            i++;
        }
        if(space) printf("\n");
        space=true;
        sort(A,A+i,comp);
        for(int j=0; j<i; j++)
            cout<<A[j].ss<<endl;
    }
    return 0;
}

