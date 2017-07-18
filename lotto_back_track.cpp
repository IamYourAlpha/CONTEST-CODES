#include<bits/stdc++.h>
using namespace std;

bool visited[100];
int cont[100];
int arr[100];
int num;
int now;

void back_track(int taken,int start) {
    if(taken == 6) {
        for(int i=0; i<5 ; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[5] <<  endl;
        return ;
    }
    for(int i = start ; i<num ; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[taken] = cont[i];
            back_track(taken+1,i);
            visited[i] = false;
        }

    }
    return ;
}




int main() {
    bool ok = false;
//freopen("take.txt","r",stdin);
    while(scanf("%d",&num)!=EOF) {
        if(num==0) return 0;
        for(int i=0; i<num; i++) cin >> cont[i];
        if(ok) cout << endl;
        ok = true;
        memset(visited,false,sizeof(visited));
        memset(arr,0,sizeof(arr));
        now = 0;
        back_track(0,0);
    }
    return 0;
}
