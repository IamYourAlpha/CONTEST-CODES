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

using namespace std;

typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                        printf("%d\n",n)
#define ps(n)                       printf("%s\n",n)
#define pl(n)                       printf("%lld\n",n);

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define all(n)                      for(int i=0;i<n;i++)
#define alls(m)                      for(int j=0;j<m;j++)
#define rep(i,a,b)                   for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all1(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

#include <stdio.h>
using namespace std;

int m, board[100020];
char text[100020];

void preprocess() {
    int i = 0, j = -1;
    board[0] = -1;
    while (i < m) {
        while (j >= 0 && text[m - i - 1] != text[m - j - 1]) // search for reversed input in original
            j = board[j]; // to find the start index of matching then print chars before this index
        i++;                  // in reserved order
        j++;
        board[i] = j;
    }
}

int kmp() {
    int i = 0, j = 0;
    while (i < m) {
        while (j >= 0 && text[i] != text[m - j - 1])
            j = board[j];
        i++;
        j++;
    }
    return i - j;
}

void get() {
    while (1) {
        text[0] = 0;
        scanf("%s", text);
        m = 0;
        while (text[m]) {
            m++;
        }
        if (m == 0)
            break;
        preprocess();
        int index = kmp();
        printf("%s", text);
        for (int i = index - 1; i >= 0; i--)
            printf("%c", text[i]);
        printf("\n");
    }
}

int main() {
    get();
    return 0;
}
