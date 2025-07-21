#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll attacked = 0;

    // Count attacked cells in rows
    for (auto r : rows)
        attacked += N;

    // Count attacked cells in columns
    for (auto c : cols)
        attacked += N;

    // Count attacked cells in diagonal 1 (a - b)
    for (auto d : diag1) {
        if (-N + 1 <= d && d <= N - 1)
            attacked += N - abs(d);
    }

    // Count attacked cells in diagonal 2 (a + b)
    for (auto d : diag2) {
        if (2 <= d && d <= 2 * N)
            attacked += N - abs(d - (N + 1));
    }

    // Inclusion-Exclusion Principle for intersections

    // Row × Column intersections
    for (auto r : rows)
        for (auto c : cols)
            attacked -= 1;

    // Row × Diag1 intersections
    for (auto r : rows)
        for (auto d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N)
                attacked -= 1;
        }

    // Row × Diag2 intersections
    for (auto r : rows)
        for (auto d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= N)
                attacked -= 1;
        }

    // Col × Diag1 intersections
    for (auto c : cols)
        for (auto d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= N)
                attacked -= 1;
        }

    // Col × Diag2 intersections
    for (auto c : cols)
        for (auto d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= N)
                attacked -= 1;
        }

    // Diag1 × Diag2 intersections
    for (auto d1 : diag1)
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                ll r = (d1 + d2) / 2;
                ll c = d2 - r;
                if (1 <= r && r <= N && 1 <= c && c <= N)
                    attacked -= 1;
            }
        }

    // Triple overlaps: Row × Col × Diag1
    for (auto r : rows)
        for (auto c : cols)
            if (diag1.count(r - c))
                attacked += 1;

    // Triple overlaps: Row × Col × Diag2
    for (auto r : rows)
        for (auto c : cols)
            if (diag2.count(r + c))
                attacked += 1;

    // Quadruple overlaps: Row × Col × Diag1 × Diag2
    for (auto r : rows)
        for (auto c : cols)
            if (diag1.count(r - c) && diag2.count(r + c))
                attacked -= 1;

    ll total_squares = N * N;
    ll occupied = M;
    ll safe_squares = total_squares - (attacked - M); // subtract overlaps correctly

    cout << safe_squares << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}