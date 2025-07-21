#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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
    ll forbidden = 0;
    
    // Squares forbidden by rows and columns
    ll row_count = rows.size();
    ll col_count = cols.size();
    forbidden += row_count * N;
    forbidden += col_count * N;
    forbidden -= row_count * col_count;
    
    // Squares forbidden by diagonals (d1: a - b = constant)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        forbidden += cnt;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                forbidden--;
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                forbidden--;
            }
        }
        
        // Add back intersections between rows and columns on this diagonal
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N && cols.count(c)) {
                forbidden++;
            }
        }
    }
    
    // Squares forbidden by diagonals (d2: a + b = constant)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        forbidden += cnt;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                forbidden--;
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                forbidden--;
            }
        }
        
        // Add back intersections between rows and columns on this diagonal
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N && cols.count(c)) {
                forbidden++;
            }
        }
    }
    
    // Subtract intersections between d1 and d2 diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                forbidden--;
            }
        }
    }
    
    // Ensure the result is non-negative
    ll safe = total - forbidden;
    if (safe < 0) safe = 0;
    cout << safe << endl;
    
    return 0;
}