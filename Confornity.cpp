using namespace std;
#include<bits/stdc++.h>

typedef long long ll;
vector<ll>vec;

string Convert_To_String(vector<ll>vec) {
    stringstream ss;
    string str;
    for(int i=0; i<vec.size(); i++) {
        ss << vec[i];
        str = ss.str();
    }
    return str;
}

int main() {
    ll n;
    string dummy;
    map<string,ll>mp;
    //freopen("tst.txt","r",stdin);
    int ans;
    while(scanf("%lld",&n)!=EOF) {
        ans = -999;
        if(n == 0) return 0;
        for(ll k =0; k<n; k++) {
            for(ll i=0; i<5; i++) {
                ll input;
                cin >> input;
                vec.push_back(input);
            }
            sort(vec.begin(),vec.end());
            string out = Convert_To_String(vec);
            if(mp[out]==0)
                mp[out] = 1;
            else
                mp[out]++;
            //cout << out << endl;
            if(mp[out]>=ans) ans = mp[out];
            vec.clear();
        }
        if(ans == 1) printf("%lld\n",n);
        else printf("%lld\n",ans);
        mp.clear();
    }
    return 0;
}
