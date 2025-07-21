#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
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
    ll unsafe = 0;
    
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();
    
    for (auto d : diag1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }
    
    for (auto d : diag2) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }
    
    set<pair<ll, ll>> intersections;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                intersections.insert({r, c});
            }
        }
    }
    
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll i_plus_j = d2;
            ll i_minus_j = d1;
            ll i = (i_plus_j + i_minus_j) / 2;
            ll j = (i_plus_j - i_minus_j) / 2;
            if ((i_plus_j + i_minus_j) % 2 == 0 && (i_plus_j - i_minus_j) % 2 == 0) {
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    if (rows.count(i) && cols.count(j)) {
                        intersections.insert({i, j});
                    }
                }
            }
        }
    }
    
    unsafe -= intersections.size();
    
    ll safe = total - unsafe;
    cout << safe << endl;
    
    return 0;
}