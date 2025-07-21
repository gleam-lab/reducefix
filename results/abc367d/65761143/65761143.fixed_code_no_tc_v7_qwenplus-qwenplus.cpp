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
    std::map<int, int> cnt_mod;
    cnt_mod[0] = 1; // base case: prefix sum 0 appears once

    int curr_prefix = 0;
    for (int x : a) {
        curr_prefix = (curr_prefix + x) % m;
        // Count how many times this mod has appeared before
        res += cnt_mod[curr_prefix];
        cnt_mod[curr_prefix]++;
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