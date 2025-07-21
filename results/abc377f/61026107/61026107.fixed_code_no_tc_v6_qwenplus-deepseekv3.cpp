#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diag1, diag2; // diag1: i-j, diag2: i+j
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = N * N;
    
    // Calculate forbidden squares
    ll forbidden = 0;
    
    // For row, column, diag1, diag2 individually
    forbidden += rows.size() * N;
    forbidden += cols.size() * N;
    
    for (ll d : diag1) {
        ll start_row = max(1LL, 1 + d);
        ll end_row = min(N, N + d);
        if (start_row > end_row) continue;
        forbidden += (end_row - start_row + 1);
    }
    
    for (ll d : diag2) {
        ll start_row = max(1LL, d - N);
        ll end_row = min(N, d - 1);
        if (start_row > end_row) continue;
        forbidden += (end_row - start_row + 1);
    }
    
    // Now subtract intersections between row and column, row and diag1, etc.
    // Intersections between rows and columns
    for (ll r : rows) {
        for (ll c : cols) {
            if (rows.count(r) && cols.count(c)) {
                forbidden--;
            }
        }
    }
    
    // Intersections between rows and diag1 (i-j = d)
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (rows.count(r) && diag1.count(r - c)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Intersections between rows and diag2 (i+j = d)
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (rows.count(r) && diag2.count(r + c)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Intersections between columns and diag1 (i = c + d)
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                if (cols.count(c) && diag1.count(r - c)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Intersections between columns and diag2 (j = d - i)
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                if (cols.count(c) && diag2.count(r + c)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Intersections between diag1 and diag2 (i = (d1 + d2)/2, j = (d2 - d1)/2)
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                if (diag1.count(r - c) && diag2.count(r + c)) {
                    forbidden++;
                }
            }
        }
    }
    
    // Now, add the squares that are occupied by existing pieces (since they were subtracted multiple times)
    forbidden -= M; // Each existing piece is counted in row, column, diag1, diag2, but should be subtracted 3 times (since total is row + column + diag1 + diag2 - intersections)
    
    ll safe = total - forbidden;
    cout << safe << "\n";
    
    return 0;
}