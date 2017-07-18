#include <stdio.h>
#include <string.h>
int win[500],lose[500];
int main()
{
    int n,i,j,k,p1,p2,h=0;
    char ss1[100],ss2[100];
    double result;
   // freopen("in10903.txt","r",stdin);
    while(scanf("%d",&n)==1&&n!=0){
        scanf("%d",&k);
        if(h==0){}
        else if(h==1)printf("\n");
        h=1;

     for(i=0;i<(k*n*(n-1)/2);i++){
      scanf("%d %s %d %s",&p1,&ss1,&p2,&ss2);

      if(strcmp(ss1,"rock")==0&&strcmp(ss2,"scissors")==0){
        win[p1-1]++;
        lose[p2-1]++;
      }
      else if(strcmp(ss2,"rock")==0&&strcmp(ss1,"scissors")==0){
         win[p2-1]++;
         lose[p1-1]++;
      }
     else if(strcmp(ss1,"paper")==0&&strcmp(ss2,"rock")==0){
       win[p1-1]++;
       lose[p2-1]++;

     }
     else if(strcmp(ss2,"paper")==0&&strcmp(ss1,"rock")==0){
       win[p2-1]++;
       lose[p1-1]++;

     }
     else if(strcmp(ss1,"scissors")==0&&strcmp(ss2,"paper")==0){
      win[p1-1]++;
      lose[p2-1]++;
     }

    else if(strcmp(ss2,"scissors")==0&&strcmp(ss1,"paper")==0){
      win[p2-1]++;
      lose[p1-1]++;
     }
     }
     for(j=0;j<n;j++){
       if(win[j]+lose[j]==0)printf("-\n");
       if(win[j]+lose[j]!=0) {
       result=(((double)win[j])/( ((double)win[j])+((double)lose[j])));
       printf("%.3lf\n",result);
       }
      win[j]=0;
      lose[j]=0;
     }

    }




    return 0;
}
