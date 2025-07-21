#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    ll total_attacked = 0;
    set<pair<ll, ll>> attacked;

    // Rows
    for (ll r : rows) {
        for (ll c = 1; c <= N; ++c) {
            if (!pieces.count({r, c})) {
                if (attacked.insert({r, c}).second) {
                    total_attacked++;
                }
            }
        }
    }

    // Columns
    for (ll c : cols) {
        for (ll r = 1; r <= N; ++r) {
            if (!pieces.count({r, c})) {
                if (attacked.insert({r, c}).second) {
                    total_attacked++;
                }
            }
        }
    }

    // Diagonal 1: x - y = const
    for (ll d : diag1) {
        ll start = max(1LL, d + 1), end = min(N, N + d);
        for (ll x = start; x <= end; ++x) {
            ll y = x - d;
            if (y >= 1 && y <= N && !pieces.count({x, y})) {
                if (attacked.insert({x, y}).second) {
                    total_attacked++;
                }
            }
        }
    }

    // Diagonal 2: x + y = const
    for (ll s : diag2) {
        ll start = max(1LL, s - N), end = min(N, s - 1);
        for (ll x = start; x <= end; ++x) {
            ll y = s - x;
            if (y >= 1 && y <= N && !pieces.count({x, y})) {
                if (attacked.insert({x, y}).second) {
                    total_attacked++;
                }
            }
        }
    }

    ll total_empty = N * N - M;
    ll result = total_empty - total_attacked;

    cout << result << "\n";

    return 0;
}