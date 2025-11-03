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
    
    // 遍历所有起点s，计算从s出发到任意t的路径和模m
    for(int s=0;s<n;s++){
        // 清空map，重新统计以s为起点的情况
        remainder_count.clear();
        
        // 计算从s开始，到各个位置t的步数（模m意义下）
        for(int t=0;t<n;t++){
            if(s==t) continue;
            
            long long step = 0;
            if(t > s){
                step = prefixsum[t] - prefixsum[s];
            } else {
                step = prefixsum[n] - prefixsum[s] + prefixsum[t];
            }
            
            int rem = step % m;
            // 如果余数为0，则这条路径满足条件
            if(rem == 0){
                count++;
            }
        }
    }
    
    cout<<count<<endl;
    return 0;
}