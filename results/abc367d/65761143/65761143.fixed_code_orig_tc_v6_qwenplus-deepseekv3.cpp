#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    for(int &x: a) {
        std::cin >> x;
        x %= m;
    }

    std::map<int, int> freq;
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
#ifndef ONLINE_JUDGE
    static std::ifstream in("in.txt");
    static std::ofstream out("out.txt");
    std::cin.rdbuf(in.rdbuf());
    std::cout.rdbuf(out.rdbuf());
#endif
    solve();
    return 0;
}