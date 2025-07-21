#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    unordered_set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll total = N * N;
    ll unsafe = 0;
    
    // Unsafe squares: rows, cols, diag1, diag2
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    
    for (ll d : diag1) {
        ll minX = max(1LL, d - N);
        ll maxX = min(N, d - 1);
        unsafe += (maxX - minX + 1);
    }
    
    for (ll d : diag2) {
        ll minX = max(1LL, 1 - d);
        ll maxX = min(N, N - d);
        unsafe += (maxX - minX + 1);
    }
    
    // Intersections: row & col, row & diag1, row & diag2, col & diag1, col & diag2, diag1 & diag2
    ll intersect = 0;
    
    // row & col
    intersect += rows.size() * cols.size();
    
    // row & diag1
    for (ll a : rows) {
        for (ll d : diag1) {
            ll b = d - a;
            if (b >= 1 && b <= N) {
                intersect++;
            }
        }
    }
    
    // row & diag2
    for (ll a : rows) {
        for (ll d : diag2) {
            ll b = a - d;
            if (b >= 1 && b <= N) {
                intersect++;
            }
        }
    }
    
    // col & diag1
    for (ll b : cols) {
        for (ll d : diag1) {
            ll a = d - b;
            if (a >= 1 && a <= N) {
                intersect++;
            }
        }
    }
    
    // col & diag2
    for (ll b : cols) {
        for (ll d : diag2) {
            ll a = b + d;
            if (a >= 1 && a <= N) {
                intersect++;
            }
        }
    }
    
    // diag1 & diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    intersect++;
                }
            }
        }
    }
    
    // Triple intersections: row & col & diag1, row & col & diag2, row & diag1 & diag2, col & diag1 & diag2
    ll triple = 0;
    
    // row & col & diag1
    for (ll a : rows) {
        for (ll b : cols) {
            if (diag1.find(a + b) != diag1.end()) {
                triple++;
            }
        }
    }
    
    // row & col & diag2
    for (ll a : rows) {
        for (ll b : cols) {
            if (diag2.find(a - b) != diag2.end()) {
                triple++;
            }
        }
    }
    
    // row & diag1 & diag2
    for (ll a : rows) {
        for (ll d1 : diag1) {
            ll b = d1 - a;
            if (b >= 1 && b <= N && diag2.find(a - b) != diag2.end()) {
                triple++;
            }
        }
    }
    
    // col & diag1 & diag2
    for (ll b : cols) {
        for (ll d1 : diag1) {
            ll a = d1 - b;
            if (a >= 1 && a <= N && diag2.find(a - b) != diag2.end()) {
                triple++;
            }
        }
    }
    
    // Quadruple intersection: row & col & diag1 & diag2
    ll quadruple = 0;
    for (ll a : rows) {
        for (ll b : cols) {
            if (diag1.find(a + b) != diag1.end() && diag2.find(a - b) != diag2.end()) {
                quadruple++;
            }
        }
    }
    
    // Applying inclusion-exclusion principle
    ll safe = total - unsafe + intersect - triple + quadruple;
    cout << safe << endl;
    
    return 0;
}