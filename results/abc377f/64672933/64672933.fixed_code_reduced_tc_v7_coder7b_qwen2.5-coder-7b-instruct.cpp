#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M;
    cin >> N >> M;
    
    set<pair<ll, ll>> occupied;
    set<ll> rows, cols, diags1, diags2;
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a + b);
        diags2.insert(a - b);
    }
    
    ll total_unavailable = 0;
    
    for (const auto& r : rows) {
        total_unavailable += N;
    }
    
    for (const auto& c : cols) {
        total_unavailable += N;
    }
    
    for (const auto& d1 : diags1) {
        total_unavailable += N;
    }
    
    for (const auto& d2 : diags2) {
        total_unavailable += N;
    }
    
    for (const auto& r : rows) {
        for (const auto& c : cols) {
            if (!occupied.count({r, c})) {
                total_unavailable -= 1;
            }
        }
    }
    
    for (const auto& r : rows) {
        for (const auto& d1 : diags1) {
            if (abs(r + d1) % 2 == 0 && !occupied.count({r, d1 - r})) {
                total_unavailable -= 1;
            }
        }
    }
    
    for (const auto& c : cols) {
        for (const auto& d2 : diags2) {
            if (abs(c - d2) % 2 == 0 && !occupied.count({d2 + c, c})) {
                total_unavailable -= 1;
            }
        }
    }
    
    cout << N * N - total_unavailable << endl;
    
    return 0;
}