#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    unordered_set<ll> occupied_rows, occupied_cols, occupied_diag1, occupied_diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll total_squares = N * N;
    ll attacked_squares = 0;

    // Rows and columns: each row or column covers N squares, subtract overlaps
    attacked_squares += rows.size() * N;
    attacked_squares += cols.size() * N;
    attacked_squares -= rows.size() * cols.size();

    // Diagonals (i + j = k) and anti-diagonals (i - j = k)
    for (ll d : diag1) {
        // For diagonal d = i + j, the number of valid (i,j) is min(d-1, 2N -d +1)
        ll lower = max(1LL, d - N);
        ll upper = min(N, d - 1);
        if (lower > upper) continue;
        attacked_squares += (upper - lower + 1);
    }

    for (ll d : diag2) {
        // For anti-diagonal d = i - j, the number of valid (i,j) is N - |d|
        ll lower_i = max(1LL, 1 + d);
        ll upper_i = min(N, N + d);
        if (lower_i > upper_i) continue;
        attacked_squares += (upper_i - lower_i + 1);
    }

    // Now, subtract the intersections between rows/columns and diagonals/anti-diagonals
    // Also, subtract the intersections between diagonals and anti-diagonals
    // And add back the squares subtracted multiple times (inclusion-exclusion)
    // But with M up to 1e3, we can handle intersections per piece

    set<pair<ll, ll>> intersections;
    for (ll a : rows) {
        for (ll b : cols) {
            intersections.insert({a, b});
        }
    }
    for (ll d : diag1) {
        // i + j = d, and i is in rows or j is in cols
        ll lower = max(1LL, d - N);
        ll upper = min(N, d - 1);
        for (ll i = lower; i <= upper; ++i) {
            ll j = d - i;
            if (rows.count(i) || cols.count(j)) {
                intersections.insert({i, j});
            }
        }
    }
    for (ll d : diag2) {
        // i - j = d, and i is in rows or j is in cols
        ll lower_i = max(1LL, 1 + d);
        ll upper_i = min(N, N + d);
        for (ll i = lower_i; i <= upper_i; ++i) {
            ll j = i - d;
            if (rows.count(i) || cols.count(j)) {
                intersections.insert({i, j});
            }
        }
    }
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            // Solve i + j = d1, i - j = d2 => i = (d1 + d2)/2, j = (d1 - d2)/2
            if ((d1 + d2) % 2 != 0) continue;
            ll i = (d1 + d2) / 2;
            ll j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                intersections.insert({i, j});
            }
        }
    }

    // Also, count the squares covered by diagonals and anti-diagonals but not by rows or columns
    // To avoid double-counting, we need to compute all unique squares covered by rows, columns, diag1, diag2
    set<pair<ll, ll>> all_attacked;
    for (ll a : rows) {
        for (ll j = 1; j <= N; ++j) {
            all_attacked.insert({a, j});
        }
    }
    for (ll b : cols) {
        for (ll i = 1; i <= N; ++i) {
            all_attacked.insert({i, b});
        }
    }
    for (ll d : diag1) {
        ll lower = max(1LL, d - N);
        ll upper = min(N, d - 1);
        for (ll i = lower; i <= upper; ++i) {
            ll j = d - i;
            all_attacked.insert({i, j});
        }
    }
    for (ll d : diag2) {
        ll lower_i = max(1LL, 1 + d);
        ll upper_i = min(N, N + d);
        for (ll i = lower_i; i <= upper_i; ++i) {
            ll j = i - d;
            all_attacked.insert({i, j});
        }
    }

    ll unique_attacked = all_attacked.size();

    // The safe squares are total_squares - unique_attacked - M (since M squares are already occupied)
    ll safe_squares = total_squares - unique_attacked;
    safe_squares = max(safe_squares, 0LL);

    cout << safe_squares << endl;

    return 0;
}