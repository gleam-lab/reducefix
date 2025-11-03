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
        // Count number of subarrays with sum divisible by m
        std::map<int, int> cnt;
        cnt[0] = 1;
        int prefix = 0;
        for(int x : a) {
            prefix = (prefix + x) % m;
            res += cnt[prefix];
            cnt[prefix]++;
        }
        return;
    }

    // We want to count pairs (i, j) such that 
    // (prefix[j] - prefix[i]) % m == sum, which means
    // prefix[j] == (prefix[i] + sum) % m
    // But we can also consider removing a middle segment
    // For a subarray [l, r], its sum is (prefix[r+1] - prefix[l]) % m
    // We want this to be 0, so prefix[r+1] == prefix[l]
    
    // Actually, we want the complement: total subarrays minus subarrays with sum ≡ 0 (mod m)
    // Total number of subarrays is n*(n+1)/2
    
    LL total_subarrays = 1LL * n * (n + 1) / 2;
    
    // Count subarrays with sum ≡ 0 (mod m)
    std::map<int, int> cnt;
    cnt[0] = 1;
    int prefix = 0;
    LL zero_sum_subarrays = 0;
    
    for(int x : a) {
        prefix = (prefix + x) % m;
        zero_sum_subarrays += cnt[prefix];
        cnt[prefix]++;
    }
    
    res = total_subarrays - zero_sum_subarrays;
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