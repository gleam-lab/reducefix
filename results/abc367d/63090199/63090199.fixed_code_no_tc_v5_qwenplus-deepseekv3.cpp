#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> prefix_sum(n+1,0);
    for(int i=0;i<n;i++){
        prefix_sum[i+1] = (prefix_sum[i] + nums[i]) % m;
    }
    long long count = 0;
    unordered_map<int, int> freq;
    freq[0] = 1;
    for(int i=1;i<=n;i++){
        count += freq[prefix_sum[i]];
        freq[prefix_sum[i]]++;
    }
    cout << count << endl;
    return 0;
}