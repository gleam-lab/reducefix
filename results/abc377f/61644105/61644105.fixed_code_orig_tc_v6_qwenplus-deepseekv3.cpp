#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: a - b, diag2: a + b
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = N * N;
    
    // Subtract squares covered by rows, columns, diagonals
    ll row_coverage = rows.size() * N;
    ll col_coverage = cols.size() * N;
    ll diag1_coverage = 0;
    for (ll d : diag1) {
        // Number of squares (i, j) where i - j = d
        // i ranges from max(1, 1 + d) to min(N, N + d)
        ll lower_i = max(1LL, 1 + d);
        ll upper_i = min(N, N + d);
        if (lower_i <= upper_i) {
            diag1_coverage += (upper_i - lower_i + 1);
        }
    }
    ll diag2_coverage = 0;
    for (ll d : diag2) {
        // Number of squares (i, j) where i + j = d
        // i ranges from max(1, d - N) to min(N, d - 1)
        ll lower_i = max(1LL, d - N);
        ll upper_i = min(N, d - 1);
        if (lower_i <= upper_i) {
            diag2_coverage += (upper_i - lower_i + 1);
        }
    }
    
    total -= (row_coverage + col_coverage + diag1_coverage + diag2_coverage);
    
    // Add back intersections
    // Rows and columns
    total += rows.size() * cols.size();
    
    // Rows and diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll j = r - d;
            if (j >= 1 && j <= N) {
                total++;
            }
        }
    }
    
    // Rows and diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll j = d - r;
            if (j >= 1 && j <= N) {
                total++;
            }
        }
    }
    
    // Columns and diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll i = c + d;
            if (i >= 1 && i <= N) {
                total++;
            }
        }
    }
    
    // Columns and diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll i = d - c;
            if (i >= 1 && i <= N) {
                total++;
            }
        }
    }
    
    // Diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d2 + d1) % 2 == 0) {
                ll i = (d2 + d1) / 2;
                ll j = (d2 - d1) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    total++;
                }
            }
        }
    }
    
    // Subtract triple intersections
    // Rows, columns, and diag1
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r - c)) {
                total--;
            }
        }
    }
    
    // Rows, columns, and diag2
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag2.count(r + c)) {
                total--;
            }
        }
    }
    
    // Rows, diag1, diag2
    for (ll r : rows) {
        for (ll d1 : diag1) {
            ll j = r - d1;
            if (j >= 1 && j <= N) {
                if (diag2.count(r + j)) {
                    total--;
                }
            }
        }
    }
    
    // Columns, diag1, diag2
    for (ll c : cols) {
        for (ll d1 : diag1) {
            ll i = c + d1;
            if (i >= 1 && i <= N) {
                if (diag2.count(i + c)) {
                    total--;
                }
            }
        }
    }
    
    // Add back the quadruple intersection
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                total++;
            }
        }
    }
    
    cout << total << "\n";
    
    return 0;
}