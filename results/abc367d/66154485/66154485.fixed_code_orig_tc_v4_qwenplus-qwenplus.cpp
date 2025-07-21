#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    long long ans = 0;
    vector<int> cnt(m);
    cnt[0] = 1; // Initialize with 0 to count subarrays starting from index 0

    long long prefix_sum = 0;
    for (int i = 0; i < 2 * n - 1; ++i) {
        prefix_sum += arr[i % n];
        int mod = ((prefix_sum % m) + m) % m; // Ensure non-negative
        ans += cnt[mod]++;
        if (i >= n - 1)
            cnt[mod]--; // Only allow windows of size up to n
    }

    cout << ans << endl;
    return 0;
}