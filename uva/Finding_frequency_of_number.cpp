using namespace std;
#include<bits/stdc++.h>

vector <int> f (10,0);

void FF(int low,int high,int n[]) {

    if(n[low] == n[high]) {
        f[n[low]] += high-low+1;
    } else {
        int mid = (high+low)/2;
        FF(low,mid,n);
        FF(mid+1,high,n);
    }
}

int main() {

    int num[10] = {1,1,1,2,2,2,3,3,4,5};
    FF(0,9,num);
    for(int i=0; i<f.size(); i++) if(f[i]!=0) cout <<  f[i] << endl;
    return 0;

}
