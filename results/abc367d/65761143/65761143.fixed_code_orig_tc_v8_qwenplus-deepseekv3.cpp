#include <bits/stdc++.h>
using LL = long long;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n);

    for(int &x: a) {
        std::cin >> x;
        x %= m;
    }

    std::vector<int> prefix(n+1, 0);
    for(int i = 0; i < n; ++i) {
        prefix[i+1] = (prefix[i] + a[i]) % m;
    }

    std::map<int, int> freq;
    LL res = 0;
    for(int i = 0; i <= n; ++i) {
        res += freq[prefix[i]];
        freq[prefix[i]]++;
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    
    int T = 1;
    while(T--) solve();
    
    return 0;
}