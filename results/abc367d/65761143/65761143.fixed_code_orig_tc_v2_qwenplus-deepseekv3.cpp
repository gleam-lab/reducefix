#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);

    for (int &x : a) {
        std::cin >> x;
        x %= m;
        if (x < 0) x += m; // Ensure the modulo is positive
    }

    std::unordered_map<int, int> mod_counts;
    mod_counts[0] = 1; // To account for subarrays starting from the beginning
    int current_mod = 0;
    LL result = 0;

    for (int x : a) {
        current_mod = (current_mod + x) % m;
        if (current_mod < 0) current_mod += m; // Ensure positive modulo
        result += mod_counts[current_mod];
        mod_counts[current_mod]++;
    }

    std::cout << result << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T = 1;
    // std::cin >> T; // Uncomment if multiple test cases are present
    while (T--) {
        solve();
    }

    return 0;
}