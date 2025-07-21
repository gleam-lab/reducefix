#include <iostream>
#include <vector>
#include <unordered_map>

using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    LL sum = 0;
    for (int &x : a) {
        std::cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = 0;
    std::unordered_map<int, LL> counts[2];
    counts[0][0]++;
    counts[1][0]++;
    LL pre = 0;
    for (int x : a) {
        pre = (pre + x) % m;
        res += counts[0].count(pre);
        res += counts[1].count(((pre - sum + m) % m) % m);
        counts[0][pre]++;
        counts[1][pre]++;
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}