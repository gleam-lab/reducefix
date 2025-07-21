#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    for(int &x: a) {
        std::cin >> x;
        x %= m;
    }

    std::unordered_map<int, int> freq;
    freq[0] = 1;  // To account for subarrays starting from index 0
    int current_sum = 0;
    LL res = 0;

    for(int x: a) {
        current_sum = (current_sum + x) % m;
        res += freq[current_sum];
        freq[current_sum]++;
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
    while(T--) solve();
    return 0;
}