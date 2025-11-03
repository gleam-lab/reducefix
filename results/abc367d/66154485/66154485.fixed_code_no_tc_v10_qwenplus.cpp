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
    
    // Use prefix sums and modulo frequency counting for efficiency
    vector<int> prefix_mod(n + 1, 0);
    vector<int> mod_count(m, 0);
    mod_count[0] = 1; // Empty prefix has sum 0
    
    int prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum = (prefix_sum + arr[i]) % m;
        if (prefix_sum < 0) prefix_sum += m; // Handle negative modulo
        prefix_mod[i + 1] = prefix_sum;
        mod_count[prefix_sum]++;
    }
    
    // Count pairs with same modulo (they form subarrays divisible by m)
    for (int i = 0; i < m; i++) {
        long long cnt = mod_count[i];
        ans += cnt * (cnt - 1) / 2;
    }
    
    cout << ans;
    return 0;
}