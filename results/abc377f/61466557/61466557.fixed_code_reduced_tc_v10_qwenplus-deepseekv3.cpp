#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<pll> q(m);
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
        rows.insert(q[i].first);
        cols.insert(q[i].second);
        diag1.insert(q[i].first - q[i].second);
        diag2.insert(q[i].first + q[i].second);
    }
    
    ll total_threatened = 0;
    
    // Rows and columns
    total_threatened += rows.size() * n;
    total_threatened += cols.size() * n;
    total_threatened -= rows.size() * cols.size();
    
    // Diagonals (i - j)
    for (auto d : diag1) {
        ll cnt = n - abs(d);
        total_threatened += cnt;
    }
    
    // Diagonals (i + j)
    for (auto d : diag2) {
        ll cnt;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n - d + 1;
        }
        total_threatened += cnt;
    }
    
    // Overlap between rows/columns and diagonals
    set<pll> intersection;
    for (auto r : rows) {
        for (auto c : cols) {
            intersection.insert({r, c});
        }
    }
    
    for (auto d : diag1) {
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= n) {
                intersection.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= n) {
                intersection.insert({r, c});
            }
        }
    }
    
    for (auto d : diag2) {
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= n) {
                intersection.insert({r, c});
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= n) {
                intersection.insert({r, c});
            }
        }
        for (auto od : diag1) {
            if ((d + od) % 2 != 0) continue;
            ll r = (d + od) / 2;
            ll c = (d - od) / 2;
            if (r >= 1 && r <= n && c >= 1 && c <= n) {
                intersection.insert({r, c});
            }
        }
    }
    
    total_threatened -= intersection.size();
    
    // Subtract the initial pieces themselves
    total_threatened -= m;
    
    ll total_squares = n * n;
    ll safe_squares = total_squares - total_threatened;
    
    cout << safe_squares << endl;
    
    return 0;
}