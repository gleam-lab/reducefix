#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first;
        for (int i = 0; i < n; i++) cin >> a[i].second;
        
        // Sort pairs by the second element to get the sum of B_i efficiently
        sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.second > y.second;
        });

        // Calculate the sum of the smallest (k-1) elements in B
        long long sum_b_k_minus_1 = 0;
        for (int i = 0; i < k - 1; ++i) {
            sum_b_k_minus_1 += a[i].second;
        }
        
        long long min_result = LLONG_MAX;
        // Try finding the best A_i to pair with the sum_b_k_minus_1
        for (int i = 0; i < k - 1; ++i) {
            long long current_result = a[i].first * (sum_b_k_minus_1 + a[i].second);
            min_result = min(min_result, current_result);
        }
        
        // Output the minimum result for the current test case
        cout << min_result << '\n';
    }
    return 0;
}