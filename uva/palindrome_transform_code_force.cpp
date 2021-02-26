using namespace std;
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
vector< pair<int,int> >viii;

int main(){
    int i,j;
    int len,pos;
    int left_right=0;
    int demo=999999;
    string S;
    int index;
    scanf("%d %d",&len,&pos);
   cin>>S;
    pos--;
    for(j=S.length()-1,i=0;i<(len/2);j--,i++){
            if(S[i]!=S[j]){
                            demo=abs(pos-i);
                            pos=i;
                    viii.push_back(make_pair(i,j));
                    left_right+=demo;
                    //printf("%d\n",pos);
                    printf("%c %c %d %d\n",S[i],S[j],i,j);
            }
    }
     int up_down=0;
    // for(int i=0;i<viii.size();i++){
      //     up_down+=abs( ( S[ viii[i].first ]-'z' )-(S[ viii[i].second ]-'z') );
     //}
//printf("%d",left_right);
    //for(int i=0;i<viii.size();i++) printf("%d %d\n",viii[i].first,viii[i].second);

            return 0;
    }
