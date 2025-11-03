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
        // All elements are valid, so we can choose any non-empty subset
        // Total subsets: 2^n - 1
        res = (1LL << n) - 1;
        std::cout << res << '\n';
        return;
    }

    // We need to find the number of non-empty subsets where sum % m == 0
    // This is equivalent to finding pairs of prefix sums with same remainder
    // But we need to handle the circular case properly
    
    std::map<int, int> freq;
    freq[0] = 1;  // Empty prefix has sum 0
    
    int prefix = 0;
    for(int x : a) {
        prefix = (prefix + x) % m;
        // Count how many previous prefixes have the same value
        res += freq[prefix];
        freq[prefix]++;
    }
    
    // For the case where a suffix sum equals the total sum
    // We need to count prefixes that equal the total sum
    prefix = 0;
    for(int x : a) {
        prefix = (prefix + x) % m;
        int target = (prefix - sum + m) % m;
        if (freq.find(target) != freq.end()) {
            // We already counted these in the first pass
            // So we don't add again
        }
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