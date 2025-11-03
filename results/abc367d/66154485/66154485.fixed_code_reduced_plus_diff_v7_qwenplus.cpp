#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long ans = 0;
    // Use prefix sums and map to count subarrays with sum divisible by m
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + arr[i]) % m;
    }
    
    // Count frequency of each remainder
    map<long long, long long> count;
    for (int i = 0; i <= n; i++) {
        count[prefix[i]]++;
    }
    
    // For each remainder, if it appears k times, we can form k*(k-1)/2 pairs
    for (auto& [rem, freq] : count) {
        ans += freq * (freq - 1) / 2;
    }
    
    cout << ans;
    return 0;
}