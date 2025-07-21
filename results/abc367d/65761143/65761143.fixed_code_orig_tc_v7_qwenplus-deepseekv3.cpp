#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    for (int &x : a) {
        std::cin >> x;
        x %= m;
    }

    std::map<int, int> prefix_counts;
    prefix_counts[0] = 1;
    int current_prefix = 0;
    LL res = 0;

    for (int x : a) {
        current_prefix = (current_prefix + x) % m;
        res += prefix_counts[current_prefix];
        prefix_counts[current_prefix]++;
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
    while (T--) solve();
    return 0;
}