#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, M;
    cin >> N >> M;
    vector<pll> pieces(M);
    set<ll> rows, cols, diag1, diag2;
    set<pll> occupied;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }
    
    ll unsafe = 0;
    
    // Rows
    unsafe += rows.size() * N;
    
    // Columns
    unsafe += cols.size() * N;
    
    // Diagonals (i - j)
    for (auto d : diag1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }
    
    // Diagonals (i + j)
    for (auto d : diag2) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }
    
    // Subtract intersections (row and column)
    unsafe -= rows.size() * cols.size();
    
    // Subtract intersections (row and diag1)
    for (auto d : diag1) {
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
    }
    
    // Subtract intersections (column and diag1)
    for (auto d : diag1) {
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }
    
    // Subtract intersections (row and diag2)
    for (auto d : diag2) {
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
    }
    
    // Subtract intersections (column and diag2)
    for (auto d : diag2) {
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }
    
    // Add back triple intersections (row, column, diag1 or diag2)
    for (auto p : pieces) {
        ll r = p.first, c = p.second;
        if (rows.count(r) && cols.count(c) && diag1.count(r - c)) {
            unsafe++;
        }
        if (rows.count(r) && cols.count(c) && diag2.count(r + c)) {
            unsafe++;
        }
        if (rows.count(r) && diag1.count(r - c) && diag2.count(r + c)) {
            unsafe++;
        }
        if (cols.count(c) && diag1.count(r - c) && diag2.count(r + c)) {
            unsafe++;
        }
    }
    
    // Subtract quadruple intersections (row, column, diag1, diag2)
    unsafe -= pieces.size();
    
    // Total safe squares
    ll total = N * N;
    ll safe = total - unsafe - M;
    
    cout << safe << endl;
    
    return 0;
}