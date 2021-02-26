#include<bits/stdc++.h>
using namespace std;

int n;
int arr[10000];
int make;
map < vector <int> , bool > seen;
vector < int > ans;

void back_track(int index,int taken,int sum) {
    if(sum==make) {
        if(seen[ans]) return ;
           seen[ans] = true;
           cout << ans[0];
            for(int i=1; i<taken; i++) cout << "+"<<ans[i];
            cout << endl;
            return ;

    }
    if(sum>make || index==n) return ;
    for(int k = index ; k<n; k++) {
        ans.push_back(arr[k]);
        back_track(k+1,taken+1,sum+arr[k]);
        ans.pop_back();
    }
}


bool comp(int x,int y){
 return x>y;
 }


int main() {
     freopen("in.txt","r",stdin);
    while(scanf("%d %d",&make,&n)==2) {
     if(make+n==0) return 0;
    for(int i=0; i<n; i++) cin >> arr[i];
        seen.clear();
        ans.clear();
        sort(arr,arr+n,comp);
        cout << "Sums of "<<make << ":"<<endl;
        back_track(0,0,0);
        if(seen.size()==0) cout << "NONE" << endl;
    }
    return 0;
}
