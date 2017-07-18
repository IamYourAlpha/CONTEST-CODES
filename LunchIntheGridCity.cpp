using namespace std;
#include<bits/stdc++.h>

int tc;

typedef struct city {
    int S;
    int A;
} cities;

const int MAX_ = 1000000+10;
cities node[MAX_];

bool cmp_1(cities a, cities b){
return (a.S < b.S);
}

bool cmp_2(cities a, cities b){
return (a.A < b.A);
}



int main() {

// freopen("in.txt","r",stdin);
    int S,A,F;
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d %d %d",&S,&A,&F);
        for(int i=0; i<F; i++)
            scanf("%d %d",&node[i].S,&node[i].A);
            sort(node,node+F,cmp_1);
            sort(node,node+F,cmp_1);
            if(F%2==0) cout << node[ F/2 ].S << node[ F/2 ].A << endl;
    }

   // for(int i=0; i<F; i++) cout << node[i].S << " " << node[i].A << endl;
    return 0;
}
