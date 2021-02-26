//
//       Filename:  c3.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  07/23/2015 08:01:33 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Tony (),
//   Organization:
//
// =====================================================================================


#include<bits/stdc++.h>
using namespace std;
#define MAX 100000000

long long arr[30000];

void prepos() {

        return;
    //  for(int i=0;i<10;i++) { cout << i  << " " << arr[i] << endl;}
}

int main() {
    long long n;
   // prepos();
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<15999; i++)
        arr[i] = arr[i-1] + i;

    while(scanf("%lld",&n)!=EOF) {
        if(n==0) return 0;
        int low = 1;
        long long high = 15000;
        long long totPage;
        long long pageNum;
        long  MinVal = 1e9;
        while(low<high) {

            long long mid = (high+low)/2;
            long long dif = arr[mid]-n;
            // cout << "dif " <<  dif << endl;
            if(dif<=MinVal && dif>=0) {
                totPage = arr[mid];
                pageNum = mid;
                MinVal = dif;
                if(dif==0) {
                    totPage = arr[mid+1];
                    pageNum = mid+1;
                }
            }
            if(n<=arr[mid]) {
                high = mid;
            } else if(n>arr[mid]) {
                low = mid+1;
            }
        }
        printf("%lld %lld\n",totPage-n,pageNum);
    }
    return 0;
}
