#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);

    int sum = 0;
    for (int &x : a) {
        std::cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    if (sum == 0) {
        std::cout << n * 1LL * (n + 1) / 2 << '\n';
        return;
    }

    std::map<int, int> cnt;
    cnt[0] = 1;
    int prefix = 0;
    LL res = 0;

    for (int x : a) {
        prefix = (prefix + x) % m;
        // Count subarrays ending here where (prefix - k*sum) % m == 0 for some k
        int target = (prefix - sum + m) % m;
        res += cnt[target];
        cnt[prefix]++;
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
#ifndef ONLINE_JUDGE
    static std::ifstream in("in.txt");
    static std::ofstream out("out.txt");
    std::cin.rdbuf(in.rdbuf());
    std::cout.rdbuf(out.rdbuf());
#endif
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}