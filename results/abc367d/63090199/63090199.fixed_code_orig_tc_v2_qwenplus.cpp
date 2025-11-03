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
    // 使用map记录每个余数出现的次数
    map<int,int> remainder_count;
    
    // 遍历所有起点s，计算从s出发到各个位置的步数对m取模的结果
    for(int s=0;s<n;s++){
        // 清空之前的统计
        remainder_count.clear();
        // 统计从s出发，经过t步后（t>=1）到达位置(s+t)%n时的前缀和模m值
        long long current_sum = 0;
        for(int t=1;t<n;t++){
            int pos = (s+t)%n;
            current_sum += nums[pos];
            int mod_val = ((current_sum % m) + m) % m; // 处理负数取模
            if(mod_val == 0){
                count++;
            }
            // 检查是否存在之前相同的余数，这意味着中间段的和能被m整除
            if(remainder_count.find(mod_val) != remainder_count.end()){
                count += remainder_count[mod_val];
            }
            remainder_count[mod_val]++;
        }
    }
    
    cout<<count<<endl;
    return 0;
}