#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // subtract intersections counted twice

    // Diagonals (a - b)
    for (auto d : diag1) {
        ll x_minus_y = d;
        // Calculate the number of (x, y) such that x - y = d and 1 <= x, y <= N
        ll x_low = max(1LL, 1 + x_minus_y);
        ll x_high = min(N, N + x_minus_y);
        if (x_high < x_low) continue;
        unsafe += x_high - x_low + 1;
    }

    // Diagonals (a + b)
    for (auto d : diag2) {
        ll x_plus_y = d;
        // Calculate the number of (x, y) such that x + y = d and 1 <= x, y <= N
        ll x_low = max(1LL, x_plus_y - N);
        ll x_high = min(N, x_plus_y - 1);
        if (x_high < x_low) continue;
        unsafe += x_high - x_low + 1;
    }

    // Subtract squares that are counted in both diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve x - y = d1 and x + y = d2
            if ((d1 + d2) % 2 != 0) continue;
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe--;
            }
        }
    }

    // Subtract squares that are in rows and diagonals
    for (auto r : rows) {
        for (auto d : diag1) {
            ll y = r - d;
            if (y >= 1 && y <= N) {
                unsafe--;
            }
        }
        for (auto d : diag2) {
            ll y = d - r;
            if (y >= 1 && y <= N) {
                unsafe--;
            }
        }
    }

    // Subtract squares that are in columns and diagonals
    for (auto c : cols) {
        for (auto d : diag1) {
            ll x = d + c;
            if (x >= 1 && x <= N) {
                unsafe--;
            }
        }
        for (auto d : diag2) {
            ll x = d - c;
            if (x >= 1 && x <= N) {
                unsafe--;
            }
        }
    }

    // Add back squares that are in rows, columns, and diagonals (inclusion-exclusion)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                unsafe += 1;
            }
        }
    }

    // Subtract the number of existing pieces (since they are not empty)
    ll total = N * N - M - unsafe;
    cout << total << "\n";

    return 0;
}