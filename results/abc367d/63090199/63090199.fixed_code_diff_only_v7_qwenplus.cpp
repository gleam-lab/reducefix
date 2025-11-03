#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    vector<int> prefixsum(n+1, 0);
    for(int i = 0; i < n; i++){
        prefixsum[i+1] = (prefixsum[i] + nums[i]) % m;
    }
    
    long long count = 0;
    unordered_map<int, int> remainder_count;
    
    // Count frequency of each prefix sum modulo m
    for(int i = 0; i <= n; i++){
        int rem = prefixsum[i] % m;
        if(rem < 0) rem += m; // Ensure non-negative remainder
        remainder_count[rem]++;
    }
    
    // For each remainder r, if there are k prefixes with remainder r,
    // then there are C(k,2) = k*(k-1)/2 pairs that form a subarray sum divisible by m
    for(auto& pair : remainder_count){
        long long k = pair.second;
        count += k * (k - 1) / 2;
    }
    
    cout << count << endl;
    return 0;
}