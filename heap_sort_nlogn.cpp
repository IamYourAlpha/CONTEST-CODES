using namespace std;
# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>


typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
int n,arr[1000];
struct MaxHeap {
    int sz;
    int* arr;
};

void swp(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void Heapify(struct MaxHeap* maxheap,int idx) {
   int P;
     P = idx;
    int l = idx*2 + 1;
    int r = idx*2 + 2;
    if(l<maxheap->sz && maxheap->arr[l] > maxheap->arr[P])
        P = l;
    if(r<maxheap->sz && maxheap->arr[r] > maxheap->arr[P])
        P = r;
    if(P != idx)
        swp(&maxheap->arr[P],&maxheap->arr[idx]);
    Heapify(maxheap,P);
}


int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    int s = sizeof(arr)/sizeof(arr[0]);
    cout << s << endl;
}






