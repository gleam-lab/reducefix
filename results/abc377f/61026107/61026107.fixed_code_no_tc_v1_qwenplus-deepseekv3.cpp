#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> points;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        points.insert({a, b});
    }

    ll unsafe = 0;
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    for (auto d : diag1) {
        ll x = max(1LL, 1 + d);
        ll y = max(1LL, 1 - d);
        ll cnt = N - max(x - 1, y - 1);
        cnt = N - abs(d);
        if (d > 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }
    for (auto d : diag2) {
        ll x = max(1LL, d - N);
        ll y = max(1LL, 2 - x);
        ll cnt = N - max(x - 1, y - 1);
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }

    // Subtract intersections counted multiple times
    for (auto r : rows) {
        for (auto c : cols) {
            if (points.count({r, c})) continue;
            if (diag1.count(r - c) && diag2.count(r + c)) {
                unsafe -= 3;
            } else if (diag1.count(r - c) || diag2.count(r + c)) {
                unsafe -= 2;
            } else {
                unsafe -= 1;
            }
        }
    }

    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c < 1 || c > N) continue;
            if (points.count({r, c})) continue;
            if (cols.count(c) && diag2.count(r + c)) {
                // covered by row, col, diag1, diag2
                continue;
            } else if (cols.count(c) || diag2.count(r + c)) {
                unsafe -= 1;
            }
        }
    }

    for (auto r : rows) {
        for (auto d2 : diag2) {
            ll c = d2 - r;
            if (c < 1 || c > N) continue;
            if (points.count({r, c})) continue;
            if (cols.count(c) && diag1.count(r - c)) {
                // covered by row, col, diag1, diag2
                continue;
            } else if (cols.count(c) || diag1.count(r - c)) {
                unsafe -= 1;
            }
        }
    }

    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = c + d1;
            if (r < 1 || r > N) continue;
            if (points.count({r, c})) continue;
            if (rows.count(r) && diag2.count(r + c)) {
                // covered by row, col, diag1, diag2
                continue;
            } else if (rows.count(r) || diag2.count(r + c)) {
                unsafe -= 1;
            }
        }
    }

    for (auto c : cols) {
        for (auto d2 : diag2) {
            ll r = d2 - c;
            if (r < 1 || r > N) continue;
            if (points.count({r, c})) continue;
            if (rows.count(r) && diag1.count(r - c)) {
                // covered by row, col, diag1, diag2
                continue;
            } else if (rows.count(r) || diag1.count(r - c)) {
                unsafe -= 1;
            }
        }
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r < 1 || r > N || c < 1 || c > N) continue;
            if (points.count({r, c})) continue;
            if (rows.count(r) && cols.count(c)) {
                // covered by row, col, diag1, diag2
                continue;
            } else if (rows.count(r) || cols.count(c)) {
                unsafe -= 1;
            }
        }
    }

    ll total = N * N;
    ll safe = total - unsafe;
    cout << safe << "\n";
    return 0;
}