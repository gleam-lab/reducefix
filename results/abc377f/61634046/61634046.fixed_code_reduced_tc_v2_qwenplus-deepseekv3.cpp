#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
    }

    unordered_set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
    }

    ll row_cnt = rows.size();
    ll col_cnt = cols.size();
    ll diag1_cnt = diag1.size();
    ll diag2_cnt = diag2.size();

    ll total = N * N - M; // Total empty squares

    // Squares in any row, column, or diagonal
    ll unsafe = row_cnt * N + col_cnt * N - row_cnt * col_cnt;

    // Add squares in diag1 (a + b = k)
    unsafe += diag1_cnt * N;
    for (auto k : diag1) {
        ll lower = max(1LL, k - N);
        ll upper = min(N, k - 1);
        if (lower > upper) continue;
        unsafe -= (upper - lower + 1);
    }

    // Add squares in diag2 (a - b = k)
    unsafe += diag2_cnt * N;
    for (auto k : diag2) {
        ll lower = max(1LL, 1 - k);
        ll upper = min(N, N - k);
        if (lower > upper) continue;
        unsafe -= (upper - lower + 1);
    }

    // Subtract intersections between rows and diag1
    for (auto r : rows) {
        for (auto k : diag1) {
            ll c = k - r;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
    }

    // Subtract intersections between rows and diag2
    for (auto r : rows) {
        for (auto k : diag2) {
            ll c = r - k;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
    }

    // Subtract intersections between columns and diag1
    for (auto c : cols) {
        for (auto k : diag1) {
            ll r = k - c;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }

    // Subtract intersections between columns and diag2
    for (auto c : cols) {
        for (auto k : diag2) {
            ll r = c + k;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }

    // Add intersections between diag1 and diag2
    for (auto k1 : diag1) {
        for (auto k2 : diag2) {
            if ((k1 + k2) % 2 != 0) continue;
            ll r = (k1 + k2) / 2;
            ll c = (k1 - k2) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                unsafe++;
            }
        }
    }

    // Add triple intersections (row, column, diag1 or diag2)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c)) {
                unsafe++;
            }
            if (diag2.count(r - c)) {
                unsafe++;
            }
        }
    }

    // Subtract quadruple intersections (row, column, diag1, diag2)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                unsafe--;
            }
        }
    }

    ll safe = total - unsafe;
    cout << safe << endl;

    return 0;
}