#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
#define x first
#define y second
#define all(x) x.begin(),x.end()

const int N = 200020, INF = 0x3f3f3f3f;
int n, m;

void solve()
{
    int q;
    cin >> n >> m >> q;
    vector<bool> row(n + 1, true);
    vector<bool> col(m + 1, true);

    auto destroy = [&](int r, int c) -> void {
        if (row[r]) {
            row[r] = false;
            col[c] = false;
        } else {
            for (int i = r - 1; i >= 1; --i) {
                if (row[i]) {
                    row[i] = false;
                    break;
                }
            }
            for (int i = r + 1; i <= n; ++i) {
                if (row[i]) {
                    row[i] = false;
                    break;
                }
            }
            for (int j = c - 1; j >= 1; --j) {
                if (col[j]) {
                    col[j] = false;
                    break;
                }
            }
            for (int j = c + 1; j <= m; ++j) {
                if (col[j]) {
                    col[j] = false;
                    break;
                }
            }
        }
    };

    while (q--) {
        int r, c; cin >> r >> c;
        destroy(r, c);
    }

    ll ans = 0;
    for (bool r : row) ans += !r;
    for (bool c : col) ans += !c;
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}