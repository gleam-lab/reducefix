#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n), prefix(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Compute prefix sums modulo m
    for (int i = 0; i < n; i++) {
        prefix[i+1] = (prefix[i] + arr[i]) % m;
    }
    
    // Count frequency of each remainder
    unordered_map<long long, long long> freq;
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += freq[prefix[i]];
        freq[prefix[i]]++;
    }
    
    cout << ans;
    return 0;
}