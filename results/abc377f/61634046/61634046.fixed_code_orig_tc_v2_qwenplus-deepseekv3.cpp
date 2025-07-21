#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    unordered_set<ll> rows, cols;
    unordered_set<ll> diag1, diag2; // diag1: i-j, diag2: i+j
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = N * N;
    
    // Subtract squares in rows, cols, diag1, diag2
    ll row_count = rows.size();
    ll col_count = cols.size();
    total -= row_count * N;
    total -= col_count * N;
    
    // Add back intersections of rows and cols
    total += row_count * col_count;
    
    // Subtract squares in diag1 and diag2
    for (ll d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        total -= cnt;
    }
    
    for (ll d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        total -= cnt;
    }
    
    // Add back intersections of rows and diag1, rows and diag2, cols and diag1, cols and diag2
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N && cols.find(c) != cols.end()) {
                total += 1;
            }
        }
        for (ll d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N && cols.find(c) != cols.end()) {
                total += 1;
            }
        }
    }
    
    // Subtract intersections of diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d2 + d1) % 2 != 0) continue;
            ll i = (d2 + d1) / 2;
            ll j = (d2 - d1) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N && rows.find(i) != rows.end() && cols.find(j) != cols.end()) {
                total -= 1;
            }
        }
    }
    
    // Add back intersections of rows, cols, diag1, diag2 (four-way)
    for (ll r : rows) {
        for (ll c : cols) {
            ll d1 = r - c;
            ll d2 = r + c;
            if (diag1.find(d1) != diag1.end() && diag2.find(d2) != diag2.end()) {
                total += 1;
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}