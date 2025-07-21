#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    int sum = 0;
    for(int &x: a) {
        std::cin >> x;
        sum = (sum + x) % m;
    }

    LL res = 0;
    std::map<int, int> prefix_sum_count;
    prefix_sum_count[0]++;

    int current_sum = 0;
    for(int x: a) {
        current_sum = (current_sum + x) % m;
        int target = ((current_sum - sum) % m + m) % m;
        res += prefix_sum_count[target];
        prefix_sum_count[current_sum]++;
    }

    std::cout << res << '\n';
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    
    return 0;
}