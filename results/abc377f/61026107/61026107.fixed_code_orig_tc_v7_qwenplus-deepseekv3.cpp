#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
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

    ll total = N * N - M;
    ll unsafe = 0;

    // Count squares threatened by rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;

    // Count squares threatened by diagonals
    for (auto d : diag1) {
        ll x_min = max(1LL, 1 + d);
        ll x_max = min(N, N + d);
        ll y_min = max(1LL, 1 - d);
        ll y_max = min(N, N - d);
        ll cnt = min(x_max - x_min + 1, y_max - y_min + 1);
        if (cnt > 0) {
            unsafe += cnt;
        }
    }

    for (auto d : diag2) {
        ll x_min = max(1LL, d - N);
        ll x_max = min(N, d - 1);
        ll y_min = max(1LL, d - N);
        ll y_max = min(N, d - 1);
        ll cnt = min(x_max - x_min + 1, y_max - y_min + 1);
        if (cnt > 0) {
            unsafe += cnt;
        }
    }

    // Subtract overlaps (squares counted multiple times)
    // Subtract squares in same row and column
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.find({r, c}) == pieces.end()) {
                unsafe--;
            }
        }
    }

    // Subtract squares in same row and diagonal1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N && pieces.find({r, c}) == pieces.end()) {
                unsafe--;
            }
        }
    }

    // Subtract squares in same row and diagonal2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N && pieces.find({r, c}) == pieces.end()) {
                unsafe--;
            }
        }
    }

    // Subtract squares in same column and diagonal1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (r >= 1 && r <= N && pieces.find({r, c}) == pieces.end()) {
                unsafe--;
            }
        }
    }

    // Subtract squares in same column and diagonal2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N && pieces.find({r, c}) == pieces.end()) {
                unsafe--;
            }
        }
    }

    // Subtract squares in same diagonal1 and diagonal2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N && pieces.find({r, c}) == pieces.end()) {
                unsafe--;
            }
        }
    }

    // Add squares that were subtracted three times (row, col, diag1 or diag2)
    // These are the squares at the intersection of row, column, and at least one diagonal
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.find({r, c}) != pieces.end()) continue;
            if (diag1.find(r - c) != diag1.end() || diag2.find(r + c) != diag2.end()) {
                unsafe++;
            }
        }
    }

    ll safe = total - unsafe;
    cout << safe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}