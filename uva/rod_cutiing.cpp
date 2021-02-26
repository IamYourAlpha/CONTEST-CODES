
//headers
using namespace std;
#include<cstring>
#include<limits>
#include<limits.h>
#include<vector>
#include<map>
#include<iostream>
#include<math.h>
#include<queue>
#include<cstdlib>
#include<ctype.h>
#include<string>
#include<cstdio>
#include<algorithm>

/**********INPUT******/
#define sint(a)     scanf("%d",&a)
#define pint(a)     printf("%d",a)
//#define sintll(a)   scanf("%lld",&a)
//#define pintll(a)   printf("%lld",a)
//#define sint2(a,b)  scanf("%d%d",&a,&b)


#define MAX(a,b) (a > b) ? (a) : (b)
#define MIN(a,b) (a < b) ? (a) : (b)
#define MIN3(a,b,c) (a < b) ? (a < c ? a : c) : (b < c ? b : c)
#define MAX3(a,b,c) (a > b) ? (a > c ? a : c) : (b > c ? b : c)
#define mem(x,y) memset(x,y,sizeof(x));
#define pb push_back
#define pf pop_front()
#define N 1000000+7


/* loops****/
#define rep(a,n) for(int a=1;a<=n;a++)
#define repo(a,n) for(int a=0;a<n;a++)

#define PINF 2147483647
#define NINF -2147483647
#define Pi acos(-1.0)

typedef priority_queue< int,vector<int>,greater<int> > my_q;


/****************** templates***********************/






vector<int> price_table;

void PriceTableInitialization(vector<int>& table) {
    table.push_back(3);
    table.push_back(5);
    table.push_back(8);
    table.push_back(9);
    table.push_back(10);
    table.push_back(17);
    table.push_back(17);
    table.push_back(20);
}

int RodCutting(int rodLen) {
    if(rodLen<=0)return 0;
    else {
        int maxPrice = INT_MIN;
        for(int i=0; i<rodLen; i++) {
            int curPrice = price_table[i]+RodCutting(rodLen-i-1);
            if(curPrice>maxPrice)maxPrice=curPrice;
        }
        return maxPrice;
    }
}


int DP_RodCutting(int rodLen) {
    int* maxValTable = new int[rodLen];
    maxValTable[0] = 0;

    for(int i=1; i<=rodLen; i++) {
        int maxPrice = INT_MIN;
        for(int j=0; j<i; j++) {
            maxPrice = max(maxPrice, price_table[j] + maxValTable[i-j-1]);
        }
        maxValTable[i] = maxPrice;
    }

    return maxValTable[rodLen];
}








int main() {

    PriceTableInitialization(price_table);
    cout<<"Recursive rod cutting: "<<RodCutting(8)<<endl;
    cout<<"Dynamic programming rod cutting: "<<DP_RodCutting(8)<<endl;
    return 0;
}
