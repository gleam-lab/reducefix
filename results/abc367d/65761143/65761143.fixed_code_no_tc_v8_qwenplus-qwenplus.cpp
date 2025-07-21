#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    int sum = 0;
    for (int &x : a) {
        std::cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = 0;
    std::map<int, int> cnt[2]; // cnt[0] for prefix sums, cnt[1] for (prefix - total_sum)
    cnt[0][0] = 1; // One occurrence of prefix sum 0 before any element

    int curr = 0;
    for (int x : a) {
        curr = (curr + x) % m;

        // Count number of previous prefix sums equal to curr
        res += cnt[0][curr];

        // Calculate (prefix - sum) mod m
        int val = ((curr - sum) % m + m) % m;
        res += cnt[1][val];

        // Update the maps for next iteration
        cnt[0][curr]++;
        cnt[1][val]++;
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T = 1;
    std::cin >> T;
    while (T--) solve();

    return 0;
}