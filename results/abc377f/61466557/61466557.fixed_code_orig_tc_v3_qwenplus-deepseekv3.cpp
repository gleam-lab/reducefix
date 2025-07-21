#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> occupied;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }
    
    ll total = N * N;
    ll attacked = 0;
    
    // Rows
    attacked += rows.size() * N;
    
    // Columns
    attacked += cols.size() * N;
    
    // Diagonals (i - j = d)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }
    
    // Anti-diagonals (i + j = d)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }
    
    // Subtract intersections: row and column
    ll row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c}) == 0) {
                row_col_intersect++;
            }
        }
    }
    attacked -= row_col_intersect;
    
    // Subtract intersections: row and diag1
    ll row_diag1_intersect = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N && occupied.count({r, c}) == 0) {
                row_diag1_intersect++;
            }
        }
    }
    attacked -= row_diag1_intersect;
    
    // Subtract intersections: row and diag2
    ll row_diag2_intersect = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= N && occupied.count({r, c}) == 0) {
                row_diag2_intersect++;
            }
        }
    }
    attacked -= row_diag2_intersect;
    
    // Subtract intersections: column and diag1
    ll col_diag1_intersect = 0;
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = c + d;
            if (1 <= r && r <= N && occupied.count({r, c}) == 0) {
                col_diag1_intersect++;
            }
        }
    }
    attacked -= col_diag1_intersect;
    
    // Subtract intersections: column and diag2
    ll col_diag2_intersect = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= N && occupied.count({r, c}) == 0) {
                col_diag2_intersect++;
            }
        }
    }
    attacked -= col_diag2_intersect;
    
    // Add back intersections: row, column, diag1 or diag2 (triple intersections)
    // Here, we consider squares that are in row, column, and any diagonal
    ll triple_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c}) == 0) {
                if (diag1.count(r - c) || diag2.count(r + c)) {
                    triple_intersect++;
                }
            }
        }
    }
    attacked += triple_intersect;
    
    // The safe squares are total squares minus attacked squares, but we must not count occupied squares
    ll safe = total - attacked - M;
    
    cout << safe << "\n";
    
    return 0;
}