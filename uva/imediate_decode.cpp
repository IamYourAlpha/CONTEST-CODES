
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
string work[10000];

bool find_(string x, string y) {
    int c=0;
    int len = min(x.length(),y.length());
    //cout << len << endl;
    for(int ii=0, jj=0; ii<len; ii++,jj++)
        if(x[ii]==y[jj]) c++;
    //cout << c << " " << len << endl;
    if(c==len) return true;
    else return false;
}

bool solve(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i!=j) {
                if(work[i].length()==work[j].length() && work[i]==work[j]) return false;
                else if(work[i].length()!=work[j].length() && find_(work[i],work[j])) return false;
            }
        }
    }
    return true;
}


int main() {
    int i;
    int k =0;
    // freopen("take.txt","r",stdin);
    //stringstream ss(stringstream ::in|stringstream ::out);
    string s;
    i=0;
    while(cin >> s) {
        work[i] = s;
        i++;
        while( cin >> s) {
            if(s=="9") break;
            work[i] = s;
            i++;
        }
        //   cout << i << endl;
        bool    flag =   solve(i);
        if(flag) cout << "Set " << ++k << " is immediately decodable"<<endl;
        else cout << "Set " << ++k << " is not immediately decodable"<<endl;
        i=0;
        for(int i=0; i<10000; i++) work[i].clear();
    }

    return 0;
}
