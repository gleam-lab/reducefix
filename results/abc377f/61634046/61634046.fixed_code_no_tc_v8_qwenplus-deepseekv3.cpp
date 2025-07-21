#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: x + y, diag2: x - y
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Overlap between rows and columns
    
    // Diagonals (x + y)
    for (ll d : diag1) {
        ll min_x = max(1LL, d - N);
        ll max_x = min(N, d - 1);
        if (max_x >= min_x) {
            unsafe += (max_x - min_x + 1);
        }
    }
    
    // Diagonals (x - y)
    for (ll d : diag2) {
        ll min_x = max(1LL, 1 + d);
        ll max_x = min(N, N + d);
        if (max_x >= min_x) {
            unsafe += (max_x - min_x + 1);
        }
    }
    
    // Overlap between diagonals and rows/columns
    for (ll r : rows) {
        for (ll d : diag1) {
            ll y = d - r;
            if (y >= 1 && y <= N) {
                unsafe -= 1;
            }
        }
        for (ll d : diag2) {
            ll y = r - d;
            if (y >= 1 && y <= N) {
                unsafe -= 1;
            }
        }
    }
    
    for (ll c : cols) {
        for (ll d : diag1) {
            ll x = d - c;
            if (x >= 1 && x <= N) {
                unsafe -= 1;
            }
        }
        for (ll d : diag2) {
            ll x = c + d;
            if (x >= 1 && x <= N) {
                unsafe -= 1;
            }
        }
    }
    
    // Overlap between both diagonals
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll x = (d1 + d2) / 2;
            ll y = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && x >= 1 && x <= N && y >= 1 && y <= N) {
                unsafe += 1;
            }
        }
    }
    
    // Total safe squares
    ll total = N * N;
    ll safe = total - unsafe;
    
    cout << safe << endl;
    
    return 0;
}