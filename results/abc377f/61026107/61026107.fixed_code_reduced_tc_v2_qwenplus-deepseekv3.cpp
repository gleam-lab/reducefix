#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> occupied;
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }
    
    ll total = N * N;
    ll forbidden = 0;
    
    // Subtract rows, columns, diagonals
    forbidden += N * rows.size();
    forbidden += N * cols.size();
    
    for (auto d : diag1) {
        ll min_x = max(1LL, 1 + d);
        ll max_x = min(N, N + d);
        ll count = max_x - min_x + 1;
        forbidden += count;
    }
    
    for (auto d : diag2) {
        ll min_x = max(1LL, d - N);
        ll max_x = min(N, d - 1);
        ll count = max_x - min_x + 1;
        forbidden += count;
    }
    
    // Add back intersections
    // Rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) || diag2.count(r + c)) {
                forbidden--;
            }
        }
    }
    
    // Rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || diag2.count(r + c)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || diag1.count(r - c)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Columns and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || diag2.count(r + c)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Columns and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || diag1.count(r - c)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                if (rows.count(r) || cols.count(c)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Add back triple overlaps
    // Rows, columns, and diag1
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c)) {
                if (diag2.count(r + c)) {
                    forbidden++;
                }
            }
        }
    }
    
    // Subtract occupied squares
    ll safe = total - forbidden + occupied.size();
    cout << safe << endl;
    
    return 0;
}