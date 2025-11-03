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
        std::map<int, int> count;
        count[0] = 1;
        int prefix = 0;
        for(int x : a) {
            prefix = (prefix + x) % m;
            res += count[prefix];
            count[prefix]++;
        }
        return;
    }

    // For non-zero total sum, we need to find pairs of indices where
    // removing a subarray makes the remaining sum divisible by m
    std::map<int, int> left_count, right_count;
    
    // Count prefix sums
    int prefix = 0;
    left_count[0] = 1;  // empty prefix
    for(int i = 0; i < n - 1; i++) {  // exclude last element for left part
        prefix = (prefix + a[i]) % m;
        left_count[prefix]++;
    }
    
    // Count suffix sums
    int suffix = 0;
    right_count[0] = 1;  // empty suffix
    for(int i = n - 1; i > 0; i--) {  // exclude first element for right part
        suffix = (suffix + a[i]) % m;
        right_count[suffix]++;
    }
    
    // For each possible split, check if we can remove a middle segment
    // such that the remaining sum is 0 mod m
    for(auto [left_sum, left_freq] : left_count) {
        // We want: (left_sum + right_sum) % m == 0
        // So right_sum should be (-left_sum) % m
        int needed_right = ((-left_sum) % m + m) % m;
        if(right_count.count(needed_right)) {
            res += (LL)left_freq * right_count[needed_right];
        }
    }
    
    // Also consider removing from beginning or end only
    // Remove prefix: remaining suffix should have sum 0 mod m
    res += right_count[0];  // remove everything before some position
    
    // Remove suffix: remaining prefix should have sum 0 mod m  
    res += left_count[0];   // remove everything after some position
    
    // Remove all but one element from middle - already counted in the loop above
    
    // Remove entire array is not allowed (need at least one element)
    // So we don't add 1 for empty array
    
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