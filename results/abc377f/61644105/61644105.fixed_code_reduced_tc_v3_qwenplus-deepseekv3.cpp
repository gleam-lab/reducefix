#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = N * N;
    ll attacked = 0;
    
    // Rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    
    // Diagonals (a - b)
    for (auto d : diag1) {
        ll start_row = max(1LL, 1 + d);
        ll end_row = min(N, N + d);
        if (start_row > end_row) continue;
        attacked += (end_row - start_row + 1);
    }
    
    // Diagonals (a + b)
    for (auto d : diag2) {
        ll start_row = max(1LL, d - N);
        ll end_row = min(N, d - 1);
        if (start_row > end_row) continue;
        attacked += (end_row - start_row + 1);
    }
    
    // Overlaps
    // Row and column overlaps
    ll row_col_overlap = rows.size() * cols.size();
    attacked -= row_col_overlap;
    
    // Row and diag1 overlaps
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
    }
    
    // Row and diag2 overlaps
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
    }
    
    // Column and diag1 overlaps
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }
    
    // Column and diag2 overlaps
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }
    
    // Diag1 and diag2 overlaps
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                attacked++;
            }
        }
    }
    
    // Row, column, and diag1 overlaps
    for (auto r : rows) {
        for (auto c : cols) {
            ll d1 = r - c;
            if (diag1.find(d1) != diag1.end()) {
                attacked++;
            }
        }
    }
    
    // Row, column, and diag2 overlaps
    for (auto r : rows) {
        for (auto c : cols) {
            ll d2 = r + c;
            if (diag2.find(d2) != diag2.end()) {
                attacked++;
            }
        }
    }
    
    // Row, diag1, and diag2 overlaps
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c < 1 || c > N) continue;
            ll d2 = r + c;
            if (diag2.find(d2) != diag2.end()) {
                attacked--;
            }
        }
    }
    
    // Column, diag1, and diag2 overlaps
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = c + d1;
            if (r < 1 || r > N) continue;
            ll d2 = r + c;
            if (diag2.find(d2) != diag2.end()) {
                attacked--;
            }
        }
    }
    
    // Row, column, diag1, and diag2 overlaps
    for (auto r : rows) {
        for (auto c : cols) {
            ll d1 = r - c;
            ll d2 = r + c;
            if (diag1.find(d1) != diag1.end() && diag2.find(d2) != diag2.end()) {
                attacked++;
            }
        }
    }
    
    ll safe = total - attacked;
    cout << safe << endl;
    
    return 0;
}