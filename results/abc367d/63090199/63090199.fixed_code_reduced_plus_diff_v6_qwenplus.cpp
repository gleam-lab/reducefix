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
    map<int, int> remainder_count;
    
    // 遍历所有起点s，计算从s出发到各个位置的步数对m取模的结果
    for(int s=0; s<n; s++){
        // 清空map用于当前起点s
        remainder_count.clear();
        
        // 计算从位置s开始，顺时针走t步的总和（t从1到n-1）
        for(int t=1; t<n; t++){
            int next_pos = (s + t) % n;
            long long step;
            
            if(next_pos >= s){
                step = prefixsum[next_pos+1] - prefixsum[s];
            }else{
                step = prefixsum[n] - prefixsum[s] + prefixsum[next_pos+1];
            }
            
            int mod = step % m;
            // 如果之前已经有过相同的余数，则可以形成合法的(s,t)对
            count += remainder_count[mod];
            remainder_count[mod]++;
        }
    }
    
    cout<<count<<endl;
    return 0;
}