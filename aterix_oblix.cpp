using namespace std;
# include <iostream>
#include<stdio.h>
# include <limits>

int C,R,Q;
int city[100][100];
int party[1000];
int city_party[100][100];

void floyd() {

    for(int k=1; k<=C; k++)
        for(int i=1; i<=C; i++)
            if(city[i][k]!=numeric_limits<int>::max())
                for(int j=1; j<=C; j++) {
                    if(city[k][j]!=numeric_limits<int>::max()) {
                        if( (city[i][k]+city[k][j]+max(city_party[i][k],city_party[k][j]))<
                                (city[i][j] + city_party[i][j]) ) {
                            city[i][j]= city[i][k] +  city[k][j];
                            city_party[i][j]= max(city_party[i][k],city_party[k][j]);
                        }
                    }
                }

}

int main() {

    int U,V,W;
    int tc=0;
    bool flag=false;
    while(true) {
        scanf("%d %d %d",&C,&R,&Q);
        if(flag) printf("\n");
        else flag=true;
        if(!C && !R && !Q) return 0;
        for(int i=1; i<=C; i++) cin>>party[i];
        for(int i=1; i<=C; i++) {
            for(int j=1; j<=C; j++) {
                if(i!=j) {
                    city[i][j]=numeric_limits<int>::max();
                    city_party[i][j]=0;
                } else {
                    city[i][i]=0;
                    city_party[i][i]= party[i];
                }
            }
        }
        for(int i=1; i<=R; i++) {
            cin>>U>>V>>W;
            city[U][V]=city[V][U]=W;
            city_party[U][V]=city_party[V][U]= max(party[U],party[V]);
        }
        floyd();
        floyd();
        cout<<"Case #"<<++tc<<endl;
        for(int i=1; i<=Q; i++) {
            cin>>U>>V;
            if(city[U][V]!=numeric_limits<int>::max())
                cout<<(city[U][V]+city_party[U][V])<<endl;
            else cout<<"-1"<<endl;
        }
    }
    return 0;
}
