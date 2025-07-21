#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define PII pair<ll, ll>
#define fi first
#define se second

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> row, col, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        row.insert(x);
        col.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    ll ans = (N - (ll)row.size()) * (N - (ll)col.size());

    // Subtract the number of points on d1 diagonals that are not already subtracted
    for (auto d : diag1) {
        set<ll> covered_row;
        for (auto x : row) {
            ll y = d - x;
            if (1 <= y && y <= N)
                covered_row.insert(x);
        }
        for (auto y : col) {
            ll x = d - y;
            if (1 <= x && x <= N)
                covered_row.insert(x);
        }

        ll len;
        if (d <= N + 1) {
            len = d - 1;
        } else {
            len = 2 * N + 1 - d;
        }

        ans -= (len - (ll)covered_row.size());
    }

    // Subtract the number of points on d2 diagonals that are not already subtracted
    for (auto d : diag2) {
        set<ll> covered_row;
        for (auto x : row) {
            ll y = x - d;
            if (1 <= y && y <= N)
                covered_row.insert(x);
        }
        for (auto y : col) {
            ll x = y + d;
            if (1 <= x && x <= N)
                covered_row.insert(x);
        }

        ll len;
        if (d >= 0) {
            len = N - d;
        } else {
            len = N + d;
        }

        ans -= (len - (ll)covered_row.size());
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}