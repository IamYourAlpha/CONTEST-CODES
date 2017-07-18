#include<stdio.h>
#include<vector>
#define N 3500
using namespace std;

int n;
int A[N];
vector<int>x;
vector<int>y;

void check(int key,int index) {
    int demo;
    int demo1=key;
    bool flag=false;
    for(int i=index; i<n; i++) {
        if(A[i]<key) {
             key=A[i];
             demo=i;
            flag=true;
        }
    }
    if(flag) {
        swap(A[index],A[demo]);
        x.push_back(index);
        y.push_back(demo);
    }
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    for(int i=0; i<n; i++) {
        int key=A[i];
        check(key,i);
    }
    printf("%d\n",x.size());
    for(int i=0;i<x.size();i++) printf("%d %d\n",x[i],y[i]);
}
