#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i-j, diag2: i+j
    
    for (int k = 0; k < M; ++k) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = N * N;
    
    ll attacked = 0;
    
    // Squares attacked by rows or columns or diagonals or anti-diagonals
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    attacked += diag1.size() * N;
    attacked += diag2.size() * N;
    
    // Subtract overlaps: row and column (intersection is a single square)
    attacked -= rows.size() * cols.size();
    
    // Subtract overlaps: row and diag1 (intersection is at most one square per row)
    for (ll a : rows) {
        for (ll d : diag1) {
            ll b = a - d;
            if (b >= 1 && b <= N) {
                attacked--;
            }
        }
    }
    
    // Subtract overlaps: row and diag2 (intersection is at most one square per row)
    for (ll a : rows) {
        for (ll s : diag2) {
            ll b = s - a;
            if (b >= 1 && b <= N) {
                attacked--;
            }
        }
    }
    
    // Subtract overlaps: column and diag1 (intersection is at most one square per column)
    for (ll b : cols) {
        for (ll d : diag1) {
            ll a = b + d;
            if (a >= 1 && a <= N) {
                attacked--;
            }
        }
    }
    
    // Subtract overlaps: column and diag2 (intersection is at most one square per column)
    for (ll b : cols) {
        for (ll s : diag2) {
            ll a = s - b;
            if (a >= 1 && a <= N) {
                attacked--;
            }
        }
    }
    
    // Subtract overlaps: diag1 and diag2 (intersection is at most one square per pair)
    for (ll d : diag1) {
        for (ll s : diag2) {
            if ((s - d) % 2 == 0) {
                ll a = (s + d) / 2;
                ll b = (s - d) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    attacked--;
                }
            }
        }
    }
    
    // Add back the triple intersections (row, column, diag1 or diag2)
    for (ll a : rows) {
        for (ll b : cols) {
            if (diag1.count(a - b)) {
                attacked++;
            }
            if (diag2.count(a + b)) {
                attacked++;
            }
        }
    }
    
    // Subtract the quadruple intersection (row, column, diag1, diag2)
    for (ll a : rows) {
        for (ll b : cols) {
            if (diag1.count(a - b) && diag2.count(a + b)) {
                attacked--;
            }
        }
    }
    
    ll safe = total - attacked;
    cout << safe << endl;
    
    return 0;
}