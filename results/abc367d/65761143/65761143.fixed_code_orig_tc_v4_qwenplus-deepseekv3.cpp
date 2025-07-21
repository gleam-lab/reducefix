#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    for(int &x: a) {
        std::cin >> x;
        x %= m;
    }

    LL res = 0;
    std::vector<int> prefix_sum(n+1, 0);
    for(int i = 0; i < n; ++i) {
        prefix_sum[i+1] = (prefix_sum[i] + a[i]) % m;
    }

    std::map<int, int> cnt;
    cnt[0] = 1;
    for(int i = 1; i <= n; ++i) {
        res += cnt[prefix_sum[i]];
        cnt[prefix_sum[i]]++;
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
    while(T--) solve();
    return 0;
}