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
    
    ll attacked_rows = rows.size() * N;
    ll attacked_cols = cols.size() * N;
    ll attacked_diag1 = 0;
    for (ll d : diag1) {
        ll start_row = max(1LL, 1 + d);
        ll end_row = min(N, N + d);
        if (end_row >= start_row) {
            attacked_diag1 += end_row - start_row + 1;
        }
    }
    ll attacked_diag2 = 0;
    for (ll d : diag2) {
        ll start_row = max(1LL, d - N);
        ll end_row = min(N, d - 1);
        if (end_row >= start_row) {
            attacked_diag2 += end_row - start_row + 1;
        }
    }
    
    ll row_col_intersect = rows.size() * cols.size();
    ll row_diag1_intersect = 0;
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                row_diag1_intersect++;
            }
        }
    }
    ll row_diag2_intersect = 0;
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                row_diag2_intersect++;
            }
        }
    }
    ll col_diag1_intersect = 0;
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                col_diag1_intersect++;
            }
        }
    }
    ll col_diag2_intersect = 0;
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                col_diag2_intersect++;
            }
        }
    }
    ll diag1_diag2_intersect = 0;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N) {
                diag1_diag2_intersect++;
            }
        }
    }
    
    ll row_col_diag1_intersect = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.find(r - c) != diag1.end()) {
                row_col_diag1_intersect++;
            }
        }
    }
    ll row_col_diag2_intersect = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag2.find(r + c) != diag2.end()) {
                row_col_diag2_intersect++;
            }
        }
    }
    ll row_diag1_diag2_intersect = 0;
    for (ll r : rows) {
        for (ll d1 : diag1) {
            for (ll d2 : diag2) {
                ll c = r - d1;
                if (c >= 1 && c <= N && r + c == d2) {
                    row_diag1_diag2_intersect++;
                }
            }
        }
    }
    ll col_diag1_diag2_intersect = 0;
    for (ll c : cols) {
        for (ll d1 : diag1) {
            for (ll d2 : diag2) {
                ll r = c + d1;
                if (r >= 1 && r <= N && r + c == d2) {
                    col_diag1_diag2_intersect++;
                }
            }
        }
    }
    ll all_intersect = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.find(r - c) != diag1.end() && diag2.find(r + c) != diag2.end()) {
                all_intersect++;
            }
        }
    }
    
    ll safe = total 
              - attacked_rows - attacked_cols - attacked_diag1 - attacked_diag2 
              + row_col_intersect + row_diag1_intersect + row_diag2_intersect 
              + col_diag1_intersect + col_diag2_intersect + diag1_diag2_intersect 
              - row_col_diag1_intersect - row_col_diag2_intersect - row_diag1_diag2_intersect 
              - col_diag1_diag2_intersect + all_intersect;
    
    cout << safe << endl;
    return 0;
}