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

    // If total sum is 0 modulo m, then every subarray has sum divisible by m
    if (sum == 0) {
        // Number of subarrays is n*(n+1)/2
        LL res = 1LL * n * (n + 1) / 2;
        std::cout << res << '\n';
        return;
    }

    // We want subarrays where sum ≡ 0 (mod m)
    // For subarray [l, r]: prefix[r] - prefix[l-1] ≡ 0 (mod m)
    // So prefix[r] ≡ prefix[l-1] (mod m)
    
    LL res = 0;
    std::map<int, int> count;
    count[0] = 1;  // Empty prefix
    int prefix = 0;
    
    for (int x : a) {
        prefix = (prefix + x) % m;
        if (prefix < 0) prefix += m;
        
        // Count how many previous prefixes have the same value
        res += count[prefix];
        count[prefix]++;
    }
    
    std::cout << res << '\n';
    return;
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