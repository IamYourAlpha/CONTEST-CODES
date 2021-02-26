/***intisar chowdhury*****/

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
#define pb push_back


typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<vector<int> > vvi;


vi F;
vi S;
ll N,demo;
ll Fir,Sec;


/*template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}
*/
bool comp1 (ll c1, ll c2) {
                if(c1>c2)   return true;
                else return false;
}
bool comp2 (ll c1, ll c2) {
                if(c1<c2)   return true;
                else return false;

}
bool comp3 (ll c1, ll c2) {
                if(c1==c2)   return true;
                else return false;

}





int main() {

//freopen ("input.txt","r",stdin);
                scanf("%lld",&N);
                Fir=0;
                Sec=0;
                for(int i=0; i<N; i++) {
                                scanf("%lld",&demo);
                                if(demo<0) {
                                                Sec+=((demo)*(-1));
                                                S.pb(demo*-1);
                                } else {
                                                Fir+=demo;
                                                F.pb(demo);
                                }
                }
                //for(int i=0;i<F.size();i++) printf("%lld",F[i]); printf("\n");
                //for(int i=0;i<S.size();i++) printf("%lld",S[i]); printf("\n");



                if(Fir>Sec) {
                                printf("first\n");
                                return 0;
                }
                if(Sec>Fir) {
                                printf("second\n");
                                return 0;
                }
                // printf("%lld\n",demo);
                if(Fir==Sec) {

                                //printf("%d %d %d\n",check1,check2,check3);
                                if(lexicographical_compare(F.begin(),F.end(),S.begin(),S.end(),comp1)) {
                                                //cout<<"comp1  here"<<endl;
                                                printf("first\n");
                                                return 0;
                                }

                                else if(lexicographical_compare(F.begin(),F.end(),S.begin(),S.end(),comp2)) {
                                                printf("second\n");
                                                return 0;
                                }
                                //  cout<<"comp2  here"<<endl;
                                if(demo<0) {
                                                printf("second\n");
                                                return 0;
                                } else {
                                                printf("first\n");
                                                return 0;
                                }
                }

}
