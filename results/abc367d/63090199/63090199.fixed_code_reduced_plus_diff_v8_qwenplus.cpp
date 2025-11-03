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
    // 初始化余数为0的情况（空前缀）
    remainder_count[0] = 1;
    
    // 遍历所有位置作为右端点
    for(int r=1; r<=n; r++){
        int remainder = prefixsum[r] % m;
        // 如果之前有相同余数的前缀，那么它们之间的子数组和能被m整除
        if(remainder_count.find(remainder) != remainder_count.end()){
            count += remainder_count[remainder];
        }
        remainder_count[remainder]++;
    }
    
    cout<<count<<endl;
    return 0;
}