#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
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

    ll unsafe_rows = rows.size();
    ll unsafe_cols = cols.size();
    ll unsafe_diag1 = diag1.size();
    ll unsafe_diag2 = diag2.size();

    // Total squares under attack by rows or columns
    ll total_unsafe = unsafe_rows * N + unsafe_cols * N - unsafe_rows * unsafe_cols;

    // Subtract squares under attack by diagonals, then add back overlaps
    for (auto d : diag1) {
        // Number of squares on the diagonal i-j = d
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        total_unsafe += cnt;
    }

    for (auto d : diag2) {
        // Number of squares on the diagonal i+j = d
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        total_unsafe += cnt;
    }

    // Subtract overlaps between rows and diagonals, and columns and diagonals
    for (auto r : rows) {
        for (auto d : diag1) {
            ll j = r - d;
            if (j >= 1 && j <= N) {
                total_unsafe--;
            }
        }
        for (auto d : diag2) {
            ll j = d - r;
            if (j >= 1 && j <= N) {
                total_unsafe--;
            }
        }
    }

    for (auto c : cols) {
        for (auto d : diag1) {
            ll i = c + d;
            if (i >= 1 && i <= N) {
                total_unsafe--;
            }
        }
        for (auto d : diag2) {
            ll i = d - c;
            if (i >= 1 && i <= N) {
                total_unsafe--;
            }
        }
    }

    // Add back squares under attack by both diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    total_unsafe++;
                }
            }
        }
    }

    // Subtract existing pieces, as they are already occupied and not under attack
    total_unsafe -= M;

    ll total_safe = N * N - total_unsafe;
    cout << total_safe << endl;

    return 0;
}