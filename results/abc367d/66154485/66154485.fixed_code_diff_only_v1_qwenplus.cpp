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
    
    // Use prefix sums and modulo counting
    vector<int> count(m, 0);
    int prefix = 0;
    
    // Empty prefix has sum 0
    count[0] = 1;
    
    for (int i = 0; i < n; i++) {
        prefix = (prefix + arr[i]) % m;
        // If we have seen this remainder before, it means there are subarrays ending here with sum divisible by m
        ans += count[prefix];
        count[prefix]++;
    }
    
    cout << ans;
    return 0;
}