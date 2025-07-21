#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    set<pair<long long, long long>> s;
    for (int i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        s.insert({x, y});
    }

    long long res = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            bool valid = true;
            for (int dx = -2; dx <= 2 && valid; ++dx) {
                for (int dy = -2; dy <= 2 && valid; ++dy) {
                    if (abs(dx) + abs(dy) == 3) {
                        if (i + dx > 0 && i + dx <= n && j + dy > 0 && j + dy <= n && s.count({i + dx, j + dy})) {
                            valid = false;
                        }
                    }
                }
            }
            if (valid) ++res;
        }
    }
    cout << res << '\n';

    return 0;
}