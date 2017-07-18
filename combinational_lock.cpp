#include<stdio.h>

int main() {
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF) {
        if(!a && !b && !c && !d) return 0;
        int tot=0;
      int  ans=1080;
          /*ans+= (a-b)<0 ? (a-b)*9+40 : (a-b)*9;
        tot  =tot+ans;
        ans=1080;
        ans += (b-c)<0 ? (b-c)*9+40 : (b-c)*9;
        tot  =tot+ans;
        ans=1080;
        ans+= (c-d)<0 ? (c-d)*9+40 : (c-d)*9;
        tot  =tot+ans;
        */
       tot= (a-b);
       // printf("%d\n",tot);
       if( tot<0) tot = tot+40;
         ans +=tot*9;
         tot=c-b;
    //     printf("%d\n",tot);

        if(tot<0) tot=tot+40;
        ans+=tot*9;
         tot=c-d;
      //   printf("%d\n",tot);

         if(tot<0) tot=tot+40;
         ans+= tot*9;
         printf("%d\n",ans);
    }
    return 0;
}

