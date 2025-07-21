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

    LL res = 0; // Initialize result to 0
    if(sum == 0) res++; // If sum is already 0, increment result once before the loop
    std::map<int, int> map[2]; // Two maps to keep track of prefix sums seen in alternating rounds
    map[0][0] = 1; // Initialize with prefix sum 0 seen once
    int pre = 0;
    for(int x: a) {
        pre = (pre + x) % m;
        // Check how many times the current prefix sum and the complement of the current prefix sum (with respect to sum) have been seen
        res += map[0].count(pre) + map[1].count(((pre - sum) % m + m) % m);
        // Update the maps for the next round
        map[0][pre]++;
        map[1][pre]++;
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