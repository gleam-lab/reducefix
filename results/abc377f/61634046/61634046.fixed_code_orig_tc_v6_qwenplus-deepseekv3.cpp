#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll N, M;
    cin >> N >> M;
    
    unordered_set<ll> rows, cols;
    unordered_set<ll> diag_sum, diag_diff;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag_sum.insert(a + b);
        diag_diff.insert(a - b);
    }
    
    ll total = N * N;
    
    // Subtract squares attacked by rows or columns
    ll row_attacks = rows.size() * N;
    ll col_attacks = cols.size() * N;
    total -= row_attacks + col_attacks;
    
    // Add back squares attacked by both row and column (intersection)
    total += rows.size() * cols.size();
    
    // Subtract squares attacked by diagonals
    for (ll s : diag_sum) {
        ll min_x = max(1LL, s - N);
        ll max_x = min(N, s - 1);
        if (max_x >= min_x) {
            total -= (max_x - min_x + 1);
        }
    }
    for (ll d : diag_diff) {
        ll min_x = max(1LL, 1 - d);
        ll max_x = min(N, N - d);
        if (max_x >= min_x) {
            total -= (max_x - min_x + 1);
        }
    }
    
    // Add back squares attacked by both diagonals (intersection)
    // For two diagonals (s1, d1) and (s2, d2), the intersection is (x, y) where:
    // x + y = s1, x - y = d2 => x = (s1 + d2)/2, y = (s1 - d2)/2
    // Must be integers and within [1, N]
    for (ll s : diag_sum) {
        for (ll d : diag_diff) {
            if ((s + d) % 2 != 0) continue;
            ll x = (s + d) / 2;
            ll y = (s - d) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                total++;
            }
        }
    }
    
    // Subtract squares attacked by row and diagonal or column and diagonal
    // For each piece (a, b), the intersection of row a and diagonal s = a + b is (a, s - a)
    // Similarly for column b and diagonal s = a + b is (s - b, b)
    // And for diagonal d = a - b, (a, a - d) and (b + d, b)
    // But to avoid double counting, we need to consider these intersections precisely.
    // We'll use the counts of such intersections.
    ll row_diag_sum = 0, row_diag_diff = 0;
    ll col_diag_sum = 0, col_diag_diff = 0;
    for (ll a : rows) {
        for (ll s : diag_sum) {
            ll y = s - a;
            if (y >= 1 && y <= N) {
                row_diag_sum++;
            }
        }
        for (ll d : diag_diff) {
            ll y = a - d;
            if (y >= 1 && y <= N) {
                row_diag_diff++;
            }
        }
    }
    for (ll b : cols) {
        for (ll s : diag_sum) {
            ll x = s - b;
            if (x >= 1 && x <= N) {
                col_diag_sum++;
            }
        }
        for (ll d : diag_diff) {
            ll x = b + d;
            if (x >= 1 && x <= N) {
                col_diag_diff++;
            }
        }
    }
    total += row_diag_sum + row_diag_diff + col_diag_sum + col_diag_diff;
    
    // Subtract squares attacked by row, column, and diagonals (triple intersections)
    // These were added back multiple times and need to be subtracted again.
    for (ll a : rows) {
        for (ll b : cols) {
            ll s = a + b;
            ll d = a - b;
            if (diag_sum.find(s) != diag_sum.end() || diag_diff.find(d) != diag_diff.end()) {
                total--;
            }
        }
    }
    
    // Add squares attacked by all four conditions (quadruple intersections)
    // These were subtracted too many times and need to be added back once.
    for (ll a : rows) {
        for (ll b : cols) {
            ll s = a + b;
            ll d = a - b;
            if (diag_sum.find(s) != diag_sum.end() && diag_diff.find(d) != diag_diff.end()) {
                total++;
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}