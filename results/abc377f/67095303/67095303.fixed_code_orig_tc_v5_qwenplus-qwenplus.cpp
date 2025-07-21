#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define PII pair<ll, ll>

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2; // diag1: i+j, diag2: i-j

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll ans = (N - rows.size()) * (N - cols.size());

    // Subtract diagonal lines from diag1: i + j = d
    for (ll d : diag1) {
        ll lo = max(1LL, d - N);
        ll hi = min(N, d - 1);
        ll len = hi - lo + 1;

        set<ll> blocked;
        for (ll x : rows) {
            ll y = d - x;
            if (y >= 1 && y <= N) {
                blocked.insert(x);
            }
        }
        for (ll y : cols) {
            ll x = d - y;
            if (x >= 1 && x <= N) {
                blocked.insert(x);
            }
        }
        ans -= (len - blocked.size());
    }

    // Subtract diagonal lines from diag2: i - j = d
    for (ll d : diag2) {
        ll lo_col = max(1LL, 1 + d);
        ll hi_col = min(N, N + d);
        ll len = max(0LL, hi_col - lo_col + 1);

        set<ll> blocked;
        for (ll x : rows) {
            ll y = x - d;
            if (y >= 1 && y <= N) {
                blocked.insert(x);
            }
        }
        for (ll y : cols) {
            ll x = y + d;
            if (x >= 1 && x <= N) {
                blocked.insert(x);
            }
        }
        // remove overlaps between diag1 and diag2
        for (ll e : diag1) {
            ll sum = e;
            ll diff = d;
            if ((sum + diff) % 2 == 0) {
                ll x = (sum + diff) / 2;
                ll y = (sum - diff) / 2;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    blocked.insert(x);
                }
            }
        }

        ans -= (len - blocked.size());
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}