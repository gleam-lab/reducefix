#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= m;
    }

    long long ans = 0;
    vector<long long> prefix_sum(n + 1, 0);
    
    // Calculate prefix sums modulo m
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = (prefix_sum[i] + arr[i]) % m;
    }
    
    // Count frequency of each remainder
    vector<long long> count(m, 0);
    for (int i = 0; i <= n; i++) {
        count[prefix_sum[i]]++;
    }
    
    // For each remainder r, if there are k occurrences, 
    // then we can form k*(k-1)/2 pairs
    for (int r = 0; r < m; r++) {
        ans += count[r] * (count[r] - 1) / 2;
    }
    
    cout << ans;
    return 0;
}