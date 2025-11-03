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

    LL res = 0;
    if(sum == 0) {
        // All subarrays that are divisible by m
        // We'll count pairs of prefix sums with same value
        std::map<int, int> cnt;
        cnt[0] = 1;
        int pre = 0;
        for(int x: a) {
            pre = (pre + x) % m;
            res += cnt[pre];
            cnt[pre]++;
        }
        return std::cout << res << '\n';
    }

    // For non-zero total sum, we need to find subarrays where
    // (prefix[j] - prefix[i]) % m == 0, which means prefix[i] == prefix[j]
    // OR subarrays where the complement exists
    std::map<int, int> cnt;
    cnt[0] = 1;
    int pre = 0;
    
    for(int x: a) {
        pre = (pre + x) % m;
        // Count how many previous prefixes have the same value (gives sum 0 mod m)
        res += cnt[pre];
        // Count how many previous prefixes have value (pre - sum + m) % m 
        // This would make the remaining part have sum 'sum' mod m
        int target = (pre - sum + m) % m;
        res += cnt[target];
        cnt[pre]++;
    }

    std::cout << res << '\n';
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