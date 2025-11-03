#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>prefixsum(n+1,0);
    for(int i=0;i<n;i++){//求前缀和
        prefixsum[i+1]=prefixsum[i]+nums[i];
    }
    int count=0;
    //寻找有可能的(s,t)对
    for(int s=1;s<=n;s++){
        for(int t=1;t<=n;t++){
            if(s==t)continue;
            int step=0;
            if(s<t){
                step=prefixsum[t]-prefixsum[s-1];
            }else{
                step=prefixsum[n]-prefixsum[s-1]+prefixsum[t];
            }
            if(step%m==0){
                count++;
            }
        }
    }
    
    cout<<count<<endl;
    return 0;
}