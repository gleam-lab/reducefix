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
    long long count=0;
    // 使用map记录每个余数出现的次数
    vector<map<int,int>> pos(m);
    
    // 预处理：将每个位置的前缀和模m的结果存入对应map
    for(int i=0;i<=n;i++){
        int r = prefixsum[i] % m;
        if(r < 0) r += m; // 处理负数取模
        pos[r][i] = 1;
    }
    
    // 对于每个余数r，计算有多少对(s,t)满足 (prefixsum[t] - prefixsum[s]) % m == 0
    // 即 prefixsum[t] % m == prefixsum[s] % m，且s != t
    for(int r=0;r<m;r++){
        long long cnt = pos[r].size();
        count += cnt * (cnt - 1); // 从cnt个位置中选两个不同的位置
    }
    
    cout<<count<<endl;
    return 0;
}