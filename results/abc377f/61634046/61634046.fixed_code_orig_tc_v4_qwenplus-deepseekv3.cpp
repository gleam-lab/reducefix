#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll total_squares = N * N;
    ll unsafe_squares = 0;

    // Subtract squares covered by rows, columns, diag1, diag2
    unsafe_squares += rows.size() * N;
    unsafe_squares += cols.size() * N;
    unsafe_squares += diag1.size() * N;
    for (ll d : diag2) {
        ll cnt;
        if (d > 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe_squares += cnt;
    }

    // Add squares covered by two constraints
    // Rows and columns
    unsafe_squares -= rows.size() * cols.size();
    // Rows and diag1
    unsafe_squares -= rows.size() * diag1.size();
    // Rows and diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                unsafe_squares -= 1;
            }
        }
    }
    // Columns and diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                unsafe_squares -= 1;
            }
        }
    }
    // Columns and diag2
    unsafe_squares -= cols.size() * diag2.size();
    // Diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N) {
                unsafe_squares -= 1;
            }
        }
    }

    // Subtract squares covered by three constraints
    // Rows, columns, and diag1
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.find(r + c) != diag1.end()) {
                unsafe_squares += 1;
            }
        }
    }
    // Rows, columns, and diag2
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag2.find(r - c) != diag2.end()) {
                unsafe_squares += 1;
            }
        }
    }
    // Rows, diag1, and diag2
    for (ll r : rows) {
        for (ll d1 : diag1) {
            ll c = d1 - r;
            if (1 <= c && c <= N && diag2.find(r - c) != diag2.end()) {
                unsafe_squares += 1;
            }
        }
    }
    // Columns, diag1, and diag2
    for (ll c : cols) {
        for (ll d1 : diag1) {
            ll r = d1 - c;
            if (1 <= r && r <= N && diag2.find(r - c) != diag2.end()) {
                unsafe_squares += 1;
            }
        }
    }

    // Add squares covered by all four constraints
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.find(r + c) != diag1.end() && diag2.find(r - c) != diag2.end()) {
                unsafe_squares -= 1;
            }
        }
    }

    ll safe_squares = total_squares - unsafe_squares;
    cout << safe_squares << endl;

    return 0;
}