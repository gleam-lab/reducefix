#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int &x : a) {
        std::cin >> x;
        x %= m;
    }

    std::map<int, int> remainderCount;
    remainderCount[0] = 1; // To consider subarrays starting from index 0
    LL res = 0;
    int prefixSum = 0;

    for (int x : a) {
        prefixSum = (prefixSum + x) % m;
        res += remainderCount[prefixSum];
        remainderCount[prefixSum]++;
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}