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
        std::cout << (LL)n * (n + 1) / 2 << '\n';
        return;
    }

    LL res = 0;
    std::map<int, int> cnt[2];
    cnt[0][0] = 1;
    cnt[1][0] = 1;

    int pre = 0;
    int curr = 0; // index to alternate between prefix maps

    for (int x : a) {
        pre = (pre + x) % m;
        res += cnt[0][pre];
        res += cnt[1][((LL)pre - sum + m) % m];

        // Alternate the current map
        curr ^= 1;
        cnt[0][pre]++;
        cnt[1][pre]++;
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

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