
#include<stdio.h>
int n,ans;
int a[100],b[100],c[100],d[100],s[100];
void init(){
    for(int i=1;i<=n;i++){
        d[i]=(1<<a[i])+(1<<b[i])+(1<<c[i]);
    }
}
int main(){
    // freopen("input.txt","r",stdin);

    int i,tm1,tm2;
    int ca=0;
    while(scanf("%d",&n)!=EOF && n){
        ans=-1;
        for(i=1;i<=n;i++){
            scanf("%d %d %d %d",&a[i],&b[i],&c[i],&s[i]);
            init();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                tm1=(d[i]&d[j]);
                if(tm1==0)
                    tm1=(d[i]|d[j]);
                else
                    continue;
                for(int k=j+1;k<=n;k++){
                    tm2=(tm1&d[k]);
                    if(tm2==0){
                        tm2=s[i]+s[j]+s[k];
                        if(tm2>ans)
                            ans=tm2;
                    }
                }
            }
        }
        printf("Case %d: %d\n",++ca,ans);
    }
    return 0;
}
