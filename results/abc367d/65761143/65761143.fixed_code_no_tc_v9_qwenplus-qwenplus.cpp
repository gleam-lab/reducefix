#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    int sum = 0;
    for (int &x : a) {
        std::cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = 0;
    std::map<int, int> cnt[2]; // cnt[0]: prefix sum freq, cnt[1]: (prefix - total_sum) mod m freq
    cnt[0][0] = 1;
    cnt[1][(0 - sum + m) % m] = 1;

    int pre = 0;
    for (int x : a) {
        pre = (pre + x) % m;

        // Count how many times this prefix sum has occurred
        res += cnt[0][pre];

        // Count how many times (prefix - total_sum) mod m == current prefix
        int target = ((pre - sum) % m + m) % m;
        res += cnt[1][target];

        // Update counters for next iteration
        cnt[0][pre]++;
        cnt[1][(pre - sum + m) % m]++;
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T = 1;
    std::cin >> T;
    while (T--) solve();

    return 0;
}