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
    // Using a hashmap to count occurrences of remainders
    map<int, int> remainder_count;
    // Calculate the number of valid (s, t) pairs
    for(int t=1;t<=n;t++){
        for(int s=1;s<t;t++){
            int step = prefixsum[t] - prefixsum[s];
            if(step % m == 0){
                count++;
            }
            remainder_count[step % m]++;
        }
    }
    // Adjust count for multiple occurrences of the same remainder
    for(const auto& p : remainder_count){
        if(p.first != 0){
            int common_divisor = m / p.first;
            count -= (p.second * (p.second - 1)) / 2;
            count += p.second;
        }
    }
    cout<<count<<endl;
    return 0;
}