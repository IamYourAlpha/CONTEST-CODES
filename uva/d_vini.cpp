#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll fibo[1000];
ll pos[1000];
int pos_[1000];
void fibonacci() {
      fibo[1]=1;
      fibo[2]=2;
      for(int i=3; i<=50; i++) {
            fibo[i] = fibo[i-1] + fibo[i-2];
            // if(fibo[i]==)
      }
}

int find_(int node) {
      for(int i=0; i<100; i++) {
            if(node==fibo[i]) return i;
      }
}

int main() {
      freopen("input.txt","r",stdin);

      fibonacci();
      int tc;
      scanf("%d",&tc);
      while(tc--) {
            int c=0;
            int n;
            scanf("%d",&n);
            int max_index = -99;
            for(int i=0; i<n; i++) {
                  int num;
                  scanf("%d",&num);
                  int pos =  find_(num);
                  pos_[c++] = pos-1;
                  max_index = max(max_index,num);
            }
            // cout << max_index << endl;
            char str[700];
            char output[700]="";
            for(int i=0; i<=find_(max_index)+1; i++)  output[i]=' ';
            output[find_(max_index)] ='\0';
            getchar();
            gets(str);
            int a =0;
            for(int i=0; i<n; i++) {
                  while(!isupper(str[a])) a++;
                  output[ pos_[i] ] = str[ a ];
                  //cout << pos_[i] << endl;
                  a++;

                  //str[i] = temp;
            }

            cout << output << endl;
            //for(int i=0;i<c;i++)  printf("%d\n",pos_[i]);

      }
      return 0;
}
