#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= m;
    }
    
    long long ans = 0;
    
    // Count frequency of prefix sums modulo m
    map<int, int> prefixCount;
    prefixCount[0] = 1; // Empty prefix has sum 0
    
    int prefixSum = 0;
    for (int i = 0; i < n; i++) {
        prefixSum = (prefixSum + arr[i]) % m;
        
        // If we have seen this remainder before, it means there are subarrays
        // ending at position i that have sum divisible by m
        if (prefixCount.find(prefixSum) != prefixCount.end()) {
            ans += prefixCount[prefixSum];
        }
        
        prefixCount[prefixSum]++;
    }
    
    cout << ans;
    return 0;
}