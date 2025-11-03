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
    for(int i=0;i<n;i++){
        prefixsum[i+1]=prefixsum[i]+nums[i];
    }
    long long count=0;
    // 使用map记录每个余数出现的次数
    map<int,int> remainder_count;
    
    // 遍历所有起点s，计算从s出发到其他位置t的距离模m的值
    for(int s=0;s<n;s++){
        // 清空map，重新开始以s为起点
        remainder_count.clear();
        
        // 计算从s出发，经过不同长度路径后的模m值
        for(int len=1;len<n;len++){
            int t = (s + len) % n;
            int step;
            if(s <= t){
                step = prefixsum[t+1] - prefixsum[s];
            }else{
                step = prefixsum[n] - prefixsum[s] + prefixsum[t+1];
            }
            int remainder = step % m;
            if(remainder == 0){
                count++;
            }
        }
    }
    
    cout<<count<<endl;
    return 0;
}