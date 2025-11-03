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

    if (sum == 0) {
        // All elements are already divisible by m, so we need to count pairs (i,j) with i < j
        // such that the subarray sum from i to j-1 is divisible by m.
        // We use prefix sums and count frequency of each remainder.
        std::map<int, int> cnt;
        cnt[0] = 1;
        int prefix = 0;
        LL res = 0;
        for (int x : a) {
            prefix = (prefix + x) % m;
            res += cnt[prefix];
            cnt[prefix]++;
        }
        std::cout << res << '\n';
        return;
    }

    // We want to find minimum number of operations to make total sum divisible by m.
    // But problem seems to be asking for something else? Let's re-analyze.

    // Actually, based on common problems, this looks like it should be counting
    // subarrays whose sum is divisible by m. But the original code is trying to do something else.

    // Let's assume the intended problem is: Count number of subarrays with sum divisible by m.
    std::map<int, int> cnt;
    cnt[0] = 1;
    int prefix = 0;
    LL res = 0;
    for (int x : a) {
        prefix = (prefix + x) % m;
        res += cnt[prefix];
        cnt[prefix]++;
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