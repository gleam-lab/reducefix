#include <iostream>
#include <vector>
#include <map>

using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);
    std::map<int, int> map[2];
    map[0][0] = 1; // Initialize the count of prefix sum from 0 to 1

    int pre = 0;
    for (int x : a) {
        std::cin >> x;
        pre = (pre + x) % m;
        map[0][pre]++;
    }

    LL res = 0;
    for (int i = 0; i < m; ++i) {
        int count = map[0][i];
        if (count > 0) {
            res += count; // Each prefix sum can form a valid pair with itself
        }
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