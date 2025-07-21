#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Calculate prefix sums modulo m
    vector<int> prefix_sum_mod_m(m, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum_mod_m[arr[i] % m]++;
    }
    
    // Count pairs with sum divisible by m
    for (int i = 0; i < m; i++) {
        if ((i * 2) % m == 0) {
            ans += prefix_sum_mod_m[i] * (prefix_sum_mod_m[i] - 1) / 2;
        } else {
            ans += prefix_sum_mod_m[i] * prefix_sum_mod_m[m - i];
        }
    }
    
    // Handle zero case separately to avoid double counting
    if (prefix_sum_mod_m[0] > 0) {
        ans += prefix_sum_mod_m[0] * (prefix_sum_mod_m[0] - 1) / 2;
    }
    
    cout << ans << endl;
    return 0;
}