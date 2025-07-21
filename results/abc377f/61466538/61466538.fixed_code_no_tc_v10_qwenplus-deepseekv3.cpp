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
    for (auto &[a, b] : queens) {
        cin >> a >> b;
    }
    
    unordered_set<ll> rows, cols, diag1, diag2;
    for (auto [a, b] : queens) {
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll unsafe_rows = rows.size() * N;
    ll unsafe_cols = cols.size() * N;
    ll unsafe_row_col_intersection = rows.size() * cols.size();
    
    ll total_unsafe = unsafe_rows + unsafe_cols - unsafe_row_col_intersection;
    
    for (ll d : diag1) {
        ll cnt = N - abs(d);
        total_unsafe += cnt;
    }
    
    for (ll d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        total_unsafe += cnt;
    }
    
    unordered_set<pll> intersections;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                intersections.insert({a, b});
            }
        }
    }
    
    for (ll a : rows) {
        for (ll b : cols) {
            intersections.insert({a, b});
        }
    }
    
    for (ll d1 : diag1) {
        for (ll a : rows) {
            ll b = a - d1;
            if (b >= 1 && b <= N) {
                intersections.insert({a, b});
            }
        }
        for (ll b : cols) {
            ll a = b + d1;
            if (a >= 1 && a <= N) {
                intersections.insert({a, b});
            }
        }
    }
    
    for (ll d2 : diag2) {
        for (ll a : rows) {
            ll b = d2 - a;
            if (b >= 1 && b <= N) {
                intersections.insert({a, b});
            }
        }
        for (ll b : cols) {
            ll a = d2 - b;
            if (a >= 1 && a <= N) {
                intersections.insert({a, b});
            }
        }
    }
    
    total_unsafe -= intersections.size();
    
    ll total_squares = N * N;
    ll safe_squares = total_squares - total_unsafe;
    cout << safe_squares << "\n";
    
    return 0;
}