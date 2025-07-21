#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);

    for (int &x : a) {
        std::cin >> x;
        x %= m;
    }

    std::unordered_map<int, int> prefix_counts;
    prefix_counts[0] = 1;
    int current_sum = 0;
    LL result = 0;

    for (int x : a) {
        current_sum = (current_sum + x) % m;
        if (current_sum < 0) current_sum += m; // Ensure it's positive
        result += prefix_counts[current_sum];
        prefix_counts[current_sum]++;
    }

    std::cout << result << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}