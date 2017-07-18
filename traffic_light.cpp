using namespace std;
#include<bits/stdc++.h>

typedef vector < int > vi;

vi v;

bool AllOn(int time) {
    int green = 0;
    int orange = 0;
    for(int i = 0; i<v.size(); i++) {
        if ( time % (v [ i ] *2) < (v [ i ] - 5) ) ++green;
        if( time > v [ i ] ) ++orange;
    }
    if(v.size() == green  && orange>0 ) return true;
    else return false;

}

int main() {
 int a,b,c;
    while( scanf("%d %d %d",&a,&b,&c)!=EOF && ( a || b || c )) {
        v.push_back(a);
        v.push_back(b);
        while(c != 0) {
            v.push_back(c);
            cin >> c;
        }
        int ans = 0;
        bool found = false;
        for ( int time = 1; time<=18000; time++) {
            if ( AllOn(time) ) {
                found = true;
                ans = time;
                break;
            }
        }
        if(found) {
            int hour = ans/(60*60);
            ans = ans%3600;
            int miin = ans/60;
            ans = ans % 60;
            int second = ans;
            printf("%02d:%02d:%02d\n",hour,miin,second);
        } else cout << "Signals fail to synchronise in 5 hours" << endl;
        v.clear();
    }
    return 0;
}


