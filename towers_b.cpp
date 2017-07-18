/*********************
Name: Intisar chowdhury

/********************/

#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

vector< pair<int,int> >viii;

int n,k;
int arr[1000];

int find_max() {
    int max_value=1>>30;
    int max_index;
    for(int i=0; i<n; i++)
        if(arr[i]>max_value) {
            max_value= arr[i];
            max_index=i;
        }
    return max_index;
}

int find_min() {
    //int ans=99999;
    int min_value=1<<30;
    int min_index;
    for(int i=0; i<n; i++)
        if(arr[i]<min_value) {
            min_value= arr[i];
            min_index=i;
        }
    return min_index;

}


int main() {
    int mini_index;
    int maxi_index;
    int ans;
    int ii;
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    // sort(arr,arr+n);
    // int max_op= arr[n-1]-arr[0];
    // int target= k-max_op;
    int final_=arr[find_max()]-arr[find_min()];
    if(final_==0){ printf("0 0"); return 0;}
    bool flag=false;
    // printf("%d\n",final_);
    for( ii=0; ii<k; ii++) {
        mini_index=find_min();
        maxi_index=find_max();
        arr[mini_index]++;
        // visited[mini_index]=true;
        arr[maxi_index]--;
         ans = arr[find_max()]- arr[find_min()];
        // printf("%d\n",ans);
        if(ans<=final_) {
            if(ans==0 || ans==final_){ flag=true;}
            final_=ans;
        }
        if(flag){
        viii.push_back(make_pair(maxi_index,mini_index));
        break;
        }
        else  viii.push_back(make_pair(maxi_index,mini_index));

    }
    sort(arr,arr+n);
    printf("%d",arr[n-1]-arr[0]);
    printf(" %d\n",viii.size());
    for(int i=0; i<viii.size(); i++) printf("%d %d\n",viii[i].first+1,viii[i].second+1);

    return 0;
}
