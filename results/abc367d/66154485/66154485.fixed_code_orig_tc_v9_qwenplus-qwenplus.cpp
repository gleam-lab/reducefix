#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Prefix sum modulo m
    long long ans = 0;
    vector<int> cnt(m, 0);
    cnt[0] = 1; // To count subarrays starting from index 0

    int prefix_sum = 0;
    for (int i = 0; i < n; ++i) {
        prefix_sum = (prefix_sum + arr[i]) % m;
        ans += cnt[prefix_sum]++;
    }

    cout << ans << "\n";
    return 0;
}