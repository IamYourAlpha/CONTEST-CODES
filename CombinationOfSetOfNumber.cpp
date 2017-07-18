using namespace std;
#include<bits/stdc++.h>

int arr[1000];
int n;
int in;
vector < int > v[100];
void swap_(int i ,int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int find_perm(int front_,int index,int back_) {

    if(index == n-1) {
       for(int k=0; k<n; k++)
        v[in].push_back(arr[k]);
        in++;
        //cout << endl;
    }
    for(int i=front_; i<back_; i++) {
        swap_(i,front_);
        find_perm(front_+1,index+1,back_);
        swap_(i,front_);
    }
}


int main() {

    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    find_perm(0,0,n);
    for(int i=0; i<6;i++)
      for(int j=0; j<v[i].size(); i++) cout << v[i][j];
    return 0;
}
