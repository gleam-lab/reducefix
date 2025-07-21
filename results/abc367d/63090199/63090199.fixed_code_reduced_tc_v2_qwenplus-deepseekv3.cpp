#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    // Calculate total sum
    long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
    
    // Case 1: Non-circular subarrays (s < t)
    vector<long long> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    unordered_map<int, int> remainder_count;
    long long count = 0;
    
    // For non-circular subarrays
    for(int i = 0; i <= n; i++){
        int rem = (prefix[i] % m + m) % m;
        count += remainder_count[rem];
        remainder_count[rem]++;
    }
    
    // Case 2: Circular subarrays (s > t)
    // These can be represented as total_sum - (prefix[t] - prefix[s])
    // Which is equivalent to total_sum - (sum from s to t-1)
    // We need (total_sum - (prefix[t] - prefix[s])) % m == 0
    // => (total_sum % m) == (prefix[t] - prefix[s]) % m
    // => (prefix[s] % m) == (prefix[t] % m - total_sum % m + m) % m
    
    unordered_map<int, int> circular_remainder_count;
    long long total_rem = (total_sum % m + m) % m;
    
    for(int i = 0; i <= n; i++){
        int rem = (prefix[i] % m + m) % m;
        int target = (rem - total_rem + m) % m;
        count += circular_remainder_count[target];
        circular_remainder_count[rem]++;
    }
    
    // Subtract the cases where s == t (which we shouldn't count)
    count -= n;
    
    cout << count << endl;
    return 0;
}