#include <iostream>
#include <vector>
#include <unordered_map>

using LL = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    
    int sum = 0;
    for (int &x : a) {
        std::cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = 0;
    if (sum == 0) res++;
    std::unordered_map<int, int> map[2];
    map[0][0]++;
    map[1][0]++;
    int pre = 0;
    for (int x : a) {
        pre = (pre + x) % m;
        res += map[0].count(pre) + map[1].count((pre - sum + m) % m);
        map[0][pre]++;
        map[1][pre]++;
    }

    std::cout << res << '\n';
}

int main() {
    int T = 1;
    std::cin >> T;
    while (T--) solve();
    return 0;
}