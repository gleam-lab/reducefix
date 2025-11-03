#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<long long>prefixsum(n+1,0);
    for(int i=0;i<n;i++){
        prefixsum[i+1]=prefixsum[i]+nums[i];
    }
    long long count=0;
    // 使用map记录每个前缀和模m的余数出现的次数
    map<int,int> remainder_count;
    for(int i=0;i<=n;i++){
        int r = (prefixsum[i] % m + m) % m; // 处理负数取模
        remainder_count[r]++;
    }
    
    // 对于每个余数，如果有k个位置具有相同的余数，
    // 那么这些位置之间可以形成k*(k-1)个满足条件的(s,t)对（s != t）
    for(auto& [rem, cnt] : remainder_count){
        if(cnt >= 2){
            count += (long long)cnt * (cnt - 1);
        }
    }
    
    cout<<count<<endl;
    return 0;
}