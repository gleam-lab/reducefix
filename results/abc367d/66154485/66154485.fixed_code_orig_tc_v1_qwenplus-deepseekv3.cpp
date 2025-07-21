#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    vector<int> mod_counts(m, 0);
    for (int i = 0; i <= n; i++) {
        int mod = (prefix_sum[i] % m + m) % m;
        mod_counts[mod]++;
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (mod_counts[i] >= 2) {
            ans += (long long)mod_counts[i] * (mod_counts[i] - 1) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}