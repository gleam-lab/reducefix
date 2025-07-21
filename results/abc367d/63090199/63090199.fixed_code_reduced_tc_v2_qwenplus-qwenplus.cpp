#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    // We only care about prefix sums mod m
    vector<int> prefixSumMod(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefixSumMod[i+1] = (prefixSumMod[i] + nums[i]) % m;
    }
    
    // To count pairs (s, t) such that sum[s:t) ≡ 0 mod m
    // Note: s and t are 1-based indices in the problem description
    // We need to count how many times (prefixSum[t] - prefixSum[s]) ≡ 0 mod m
    // Which means prefixSum[t] ≡ prefixSum[s] mod m
    
    unordered_map<int, int> freq;
    long long count = 0;
    
    // For each prefix sum, count how many times we've seen this modulo value before
    for(int i = 0; i <= n; i++){
        count += freq[prefixSumMod[i]]++;
    }
    
    cout << count << endl;
    return 0;
}