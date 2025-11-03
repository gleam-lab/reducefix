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
    std::map<int, int> prefix_count;
    prefix_count[0] = 1; // Empty prefix has sum 0
    int pre = 0;
    
    for(int x: a) {
        pre = (pre + x) % m;
        
        // Count subarrays ending at current position with sum ≡ 0 (mod m)
        if (prefix_count.find(pre) != prefix_count.end()) {
            res += prefix_count[pre];
        }
        
        // For subarrays with sum ≡ sum (mod m), we need (current_prefix - target_prefix) ≡ sum (mod m)
        // So target_prefix ≡ (pre - sum + m) % m
        int target = (pre - sum + m) % m;
        if (prefix_count.find(target) != prefix_count.end()) {
            res += prefix_count[target];
        }
        
        prefix_count[pre]++;
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