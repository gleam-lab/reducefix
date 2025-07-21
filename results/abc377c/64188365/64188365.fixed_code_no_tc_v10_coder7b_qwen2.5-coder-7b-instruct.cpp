#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    long long n, m, a, b;
    cin >> n >> m;
    int ans = 0;
    set<pair<ll, ll>> c;
    rep(i, m) {
        cin >> a >> b;
        a--, b--;
        c.emplace(a, b);
    }

    rep(i, n) {
        rep(j, n) {
            bool valid = true;
            vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
            for (auto& dir : directions) {
                int x = i + dir.first, y = j + dir.second;
                if (x >= 0 && x < n && y >= 0 && y < n && c.count({x, y})) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans++;
        }
    }

    cout << ans << endl;
}