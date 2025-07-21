#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    vector<ll> a(M), b(M);
    unordered_set<ll> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
    }
    
    ll total = N * N;
    ll row_threat = rows.size() * N;
    ll col_threat = cols.size() * N;
    
    ll diag1_threat = 0;
    for (auto d : diag1) {
        ll min_val = max(1LL, d - N);
        ll max_val = min(N, d - 1);
        if (min_val > max_val) continue;
        diag1_threat += (max_val - min_val + 1);
    }
    
    ll diag2_threat = 0;
    for (auto d : diag2) {
        ll min_val = max(1LL, 1 - d);
        ll max_val = min(N, N - d);
        if (min_val > max_val) continue;
        diag2_threat += (max_val - min_val + 1);
    }
    
    ll row_col = rows.size() * cols.size();
    
    ll row_diag1 = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                row_diag1++;
            }
        }
    }
    
    ll row_diag2 = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                row_diag2++;
            }
        }
    }
    
    ll col_diag1 = 0;
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                col_diag1++;
            }
        }
    }
    
    ll col_diag2 = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d + c;
            if (1 <= r && r <= N) {
                col_diag2++;
            }
        }
    }
    
    ll diag1_diag2 = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N) {
                diag1_diag2++;
            }
        }
    }
    
    ll row_col_diag1 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.find(r + c) != diag1.end()) {
                row_col_diag1++;
            }
        }
    }
    
    ll row_col_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag2.find(r - c) != diag2.end()) {
                row_col_diag2++;
            }
        }
    }
    
    ll row_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = d1 - r;
            if (1 <= c && c <= N && diag2.find(r - c) != diag2.end()) {
                row_diag1_diag2++;
            }
        }
    }
    
    ll col_diag1_diag2 = 0;
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = d1 - c;
            if (1 <= r && r <= N && diag2.find(r - c) != diag2.end()) {
                col_diag1_diag2++;
            }
        }
    }
    
    ll row_col_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.find(r + c) != diag1.end() && diag2.find(r - c) != diag2.end()) {
                row_col_diag1_diag2++;
            }
        }
    }
    
    ll threatened = row_threat + col_threat + diag1_threat + diag2_threat
                  - row_col - row_diag1 - row_diag2 - col_diag1 - col_diag2 - diag1_diag2
                  + row_col_diag1 + row_col_diag2 + row_diag1_diag2 + col_diag1_diag2
                  - row_col_diag1_diag2;
    
    ll safe = total - threatened;
    cout << safe << endl;
    
    return 0;
}