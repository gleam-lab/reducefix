#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, M;
    cin >> N >> M;
    vector<pll> queens(M);
    set<ll> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = N * N;
    ll attacked = 0;
    
    // Squares attacked by rows or columns
    ll row_attacks = rows.size() * N;
    ll col_attacks = cols.size() * N;
    ll row_col_intersect = rows.size() * cols.size();
    attacked += row_attacks + col_attacks - row_col_intersect;
    
    // Squares attacked by diagonals (i-j)
    for (ll d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }
    
    // Squares attacked by diagonals (i+j)
    for (ll d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }
    
    // Subtract squares double-counted between diagonals and rows/columns
    set<pll> intersections;
    for (ll d : diag1) {
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (ll c : cols) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
    }
    for (ll d : diag2) {
        for (ll r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (ll c : cols) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
    }
    attacked -= intersections.size();
    
    // Subtract squares that are occupied by existing queens
    ll safe = total - attacked - M;
    
    cout << safe << "\n";
    
    return 0;
}