#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first;
    for (int i = 0; i < n; i++) cin >> ab[i].second;
    
    // Sort the pairs in descending order based on A_i
    sort(ab.begin(), ab.end(), greater<pair<int, int>>());
    
    // Compute prefix sum for B
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + ab[i - 1].second;
    }
    
    // Initialize min_value with a very large number
    int min_value = INT_MAX;
    
    // Calculate min_value using the first k elements
    int sum_B = prefix[k];
    min_value = min(min_value, ab[k - 1].first * sum_B);
    
    // Update min_value by considering each remaining element as the new maximum
    for (int i = k; i < n; i++) {
        sum_B -= ab[i - k].second;
        sum_B += ab[i].second;
        min_value = min(min_value, (ab[i].first) * sum_B);
    }
    
    // Output the result for the current test case
    cout << min_value << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}