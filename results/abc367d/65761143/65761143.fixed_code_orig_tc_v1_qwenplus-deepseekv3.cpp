#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    for(int &x: a) {
        std::cin >> x;
        x %= m;
    }

    std::map<int, int> mod_count;
    mod_count[0] = 1; // To account for subarrays starting from index 0
    LL res = 0;
    int prefix_mod = 0;

    for(int x: a) {
        prefix_mod = (prefix_mod + x) % m;
        res += mod_count[prefix_mod];
        mod_count[prefix_mod]++;
    }

    std::cout << res << '\n';
    return;
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
    while(T--) solve();
    return 0;
}