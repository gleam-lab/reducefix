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
    std::map<int, int> cnt;
    cnt[0] = 1;
    int prefix = 0;

    for (int x : a) {
        prefix = (prefix + x) % m;
        int target1 = prefix;
        int target2 = (prefix - sum + m) % m;
        if (target1 == target2) {
            res += cnt[target1];
        } else {
            res += cnt[target1];
            res += cnt[target2];
        }
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