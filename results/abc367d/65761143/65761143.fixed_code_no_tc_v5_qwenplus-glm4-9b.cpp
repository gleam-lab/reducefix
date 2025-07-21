#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<int> prefix(n + 1, 0);

    int sum = 0;
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] %= m;
        sum = (sum + a[i]) % m;
        prefix[i + 1] = sum;
    }

    LL res = 0;
    std::map<int, int> counts[2];
    counts[0][0] = 1;
    for(int i = 0; i <= n; ++i) {
        int cur = prefix[i] == 0 ? m - 1 : prefix[i] - 1;
        res += counts[0][cur];
        counts[1][cur]++;
        counts[1][prefix[i]]++;
        counts[0][prefix[i]]++;
    }

    std::cout << res << '\n';
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
    static std::ifstream in("in.txt");
    static std::ofstream out("out.txt");
    std::cin.rdbuf(in.rdbuf());
    std::cout.rdbuf(out.rdbuf());
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
#endif
    int T = 1;
    // std::cin >> T;
    while(T--) solve();
#ifndef ONLINE_JUDGE
    std::chrono::system_clock::time_point stop = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << "Run Time: " << duration << "ms\n";
#endif
    return 0;
}