// anagram

using namespace std;
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include<stdlib.h>
char inp[1000];
char out[1000];
char v[1000];
char mark[128][1000];
int value[128];

void permute(int i,int len)
{
    int c;


    if(i==len)
    {
        out[i]=0;
        puts(out);
    }
    else
    {

        for(c=0; c<len; c++)
            if(!v[c] && !mark[inp[c]][i])
            {

                mark[inp[c]][i]=1;
                v[c]=1;
                out[i]=inp[c];
                cout<<out[i]<<endl;
                permute(i+1,len);
                v[c]=0;
            }
    }
    for(c=0; c<26; c++) mark[c+'a'][i]=mark[c+'A'][i]=0;

}


int cmp(const void*a,const void*b)
{
    return value[*(char*)a]-value[*(char*)b];
}


int main()
{

    int n,k,val;
    for(n=0; n<1000; n++)
        v[n]=0;
    for(n=0; n<128; n++) for(k=0; k<1000; k++)
            mark[n][k]=0;
    val=0;
    for( n=0; n<26; n++)
    {
        value[n+'A']=val;
        cout<<"1 : "<<val<<endl;
        value[n+'a']=val+1;
       // cout<<"2 : "<<val<<endl;
        val+=2;
       // cout<<"3 : "<<val<<endl;
    }
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(inp);
        qsort(inp,strlen(inp),1,&cmp);
        permute(0,strlen(inp));
    }
    return 0;

}
