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
    // 初始化：前缀和为0的情况（对应空前缀）
    remainder_count[0] = 1;
    
    for(int i=1;i<=n;i++){
        int r = (prefixsum[i] % m + m) % m; // 处理负数取模
        if(remainder_count.find(r) != remainder_count.end()){
            count += remainder_count[r];
        }
        remainder_count[r]++;
    }
    
    // 减去s==t的情况，即长度为0的子数组
    // 在我们的方法中，每个位置自己与自己的匹配被计算了一次（当两个相同余数相遇时）
    // 但实际上我们只想要非空子数组，而标准前缀和方法已经避免了这个问题
    // 实际上上面的方法正确计算了所有和为m倍数的子数组数量
    
    cout<<count<<endl;
    return 0;
}