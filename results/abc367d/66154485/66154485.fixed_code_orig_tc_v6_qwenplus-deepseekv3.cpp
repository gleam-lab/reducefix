#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix_sum(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i % n];
    }

    long long ans = 0;
    unordered_map<int, int> mod_count;
    mod_count[0] = 1;

    for (int i = 1; i <= 2 * n; i++) {
        int mod = (prefix_sum[i] % m + m) % m;
        if (i > n) {
            int prev_mod = (prefix_sum[i - n] % m + m) % m;
            mod_count[prev_mod]--;
        }
        ans += mod_count[mod];
        mod_count[mod]++;
    }

    cout << ans << endl;
    return 0;
}