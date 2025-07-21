#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    unordered_set<ll> rows, cols, diag1, diag2;
    unordered_set<ll> unsafe_squares;

    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] - b[i]);
        diag2.insert(a[i] + b[i]);
        unsafe_squares.insert((a[i] - 1) * N + b[i] - 1);
    }

    ll total = N * N;
    ll unsafe = 0;

    // Subtract squares in occupied rows and columns, then add back intersections (occupied squares)
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    // Subtract squares in diagonals, then add back intersections with rows and columns
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        ll intersections = 0;
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (cols.find(c) == cols.end()) {
                    intersections++;
                }
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                if (rows.find(r) == rows.end()) {
                    intersections++;
                }
            }
        }
        unsafe -= intersections;
    }

    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        ll intersections = 0;
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (cols.find(c) == cols.end()) {
                    intersections++;
                }
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                if (rows.find(r) == rows.end()) {
                    intersections++;
                }
            }
        }
        unsafe -= intersections;
    }

    // Add back the squares that were subtracted twice (intersections of rows, columns, and diagonals)
    // This is complex, so we use inclusion-exclusion principle or track unsafe squares properly
    // However, for large N, it's impractical to track each square, so we need a mathematical approach

    // The problem is simplified by realizing that the total unsafe squares can be computed as
    // the union of all rows, columns, and diagonals, minus overlaps, plus the initially placed pieces
    // But the initial approach may not account for all overlaps correctly

    // Alternative approach: Track all unsafe squares directly
    // Since N is up to 1e9 and M is up to 1e3, we can't track all squares, but we can compute the unsafe squares
    // using the formula: unsafe = (rows + cols + diag1 + diag2) - (row_col + row_diag1 + row_diag2 + col_diag1 + col_diag2 + diag1_diag2) + (row_col_diag1 + row_col_diag2 + ...) - ... 

    // However, implementing inclusion-exclusion for all possible overlaps is complex and error-prone

    // Instead, recognize that the total safe squares is total squares (N^2) minus the number of unique unsafe squares
    // The number of unique unsafe squares is:
    // (rows ∪ cols ∪ diag1 squares ∪ diag2 squares) - M (since the initial pieces are already in unsafe_squares)

    // So, we need to compute the size of the union of all rows, columns, and diagonals

    // First, compute the number of unique squares in rows
    ll row_squares = rows.size() * N;

    // Then, columns (excluding those already in rows)
    ll col_squares = cols.size() * (N - rows.size());

    // Then, diag1 (excluding those already in rows or columns)
    ll diag1_squares = 0;
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                cnt--;
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                cnt--;
            }
        }
        diag1_squares += cnt;
    }

    // Then, diag2 (excluding those already in rows, columns, or diag1)
    ll diag2_squares = 0;
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                cnt--;
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                cnt--;
            }
        }
        for (auto d1 : diag1) {
            ll r = (d + d1) / 2;
            ll c = (d - d1) / 2;
            if ((d + d1) % 2 == 0 && (d - d1) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N) {
                cnt--;
            }
        }
        diag2_squares += cnt;
    }

    ll total_unsafe = row_squares + col_squares + diag1_squares + diag2_squares + M;

    // But this might still double-count overlaps between diagonals, etc.

    // Alternatively, compute the total as:
    // total_unsafe = (rows) + (cols not in rows) + (diag1 not in rows or cols) + (diag2 not in rows, cols, or diag1)
    // This is similar to inclusion-exclusion principle

    total_unsafe = rows.size() * N;
    unordered_set<ll> cols_not_in_rows;
    for (auto c : cols) {
        if (rows.find(c) == rows.end()) {
            cols_not_in_rows.insert(c);
        }
    }
    total_unsafe += cols_not_in_rows.size() * N;

    unordered_set<ll> diag1_sqs;
    for (auto d : diag1) {
        for (ll r = 1; r <= N; ++r) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (rows.find(r) == rows.end() && cols.find(c) == cols.end()) {
                    diag1_sqs.insert((r - 1) * N + c - 1);
                }
            }
        }
    }
    total_unsafe += diag1_sqs.size();

    unordered_set<ll> diag2_sqs;
    for (auto d : diag2) {
        for (ll r = 1; r <= N; ++r) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (rows.find(r) == rows.end() && cols.find(c) == cols.end()) {
                    ll key = (r - 1) * N + c - 1;
                    if (diag1_sqs.find(key) == diag1_sqs.end()) {
                        diag2_sqs.insert(key);
                    }
                }
            }
        }
    }
    total_unsafe += diag2_sqs.size();

    total_unsafe += M;

    ll answer = N * N - total_unsafe;
    if (answer < 0) answer = 0;
    cout << answer << endl;

    return 0;
}