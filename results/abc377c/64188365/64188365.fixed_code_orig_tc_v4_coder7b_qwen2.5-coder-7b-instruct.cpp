#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, a, b;
    cin >> n >> m;
    set<pair<long long, long long>> c;
    rep(i, m) {
        cin >> a >> b;
        a--, b--;
        c.emplace(a, b);
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        rep(j, 8) {
            long long x = a + dx[j], y = b + dy[j];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                c.emplace(x, y);
            }
        }
    }
    cout << n * n - c.size() << endl;
    return 0;
}