#include <iostream>
#include <vector>
#include <unordered_map>

using LL = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);

    int sum = 0;
    for (int &x : a) {
        std::cin >> x;
        x = (x % m + m) % m; // Ensure x is non-negative
        sum = (sum + x) % m;
    }

    if (sum == 0) {
        std::cout << 0 << '\n';
        return;
    }

    std::unordered_map<int, int> mp;
    LL res = 0;
    for (int x : a) {
        res += mp[m - x % m];
        mp[x % m]++;
    }
    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}