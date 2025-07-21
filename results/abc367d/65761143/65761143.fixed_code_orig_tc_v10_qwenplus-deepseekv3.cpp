#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    for(int &x: a) {
        std::cin >> x;
        x %= m;
    }

    std::unordered_map<int, LL> freq;
    freq[0] = 1;
    int prefix = 0;
    LL res = 0;

    for(int x: a) {
        prefix = (prefix + x) % m;
        res += freq[prefix];
        freq[prefix]++;
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int T = 1;
    while(T--) solve();
    return 0;
}