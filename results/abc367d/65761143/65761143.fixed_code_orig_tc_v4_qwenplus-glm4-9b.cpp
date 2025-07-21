#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    int sum = 0;
    for(int &x: a) {
        std::cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = sum ? 0 : 1;
    std::map<int, int> map[2];
    map[0][0] = 1; // Initialize with 1 to account for the initial sum = 0 case
    int pre = 0;

    for(int x: a) {
        pre = (pre + x) % m;
        map[0][pre]++;
        res += map[1][((pre - sum + m) % m)];
        map[1][pre]++;
    }

    std::cout << res << '\n';
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T = 1;
    // std::cin >> T;
    while(T--) solve();
    return 0;
}