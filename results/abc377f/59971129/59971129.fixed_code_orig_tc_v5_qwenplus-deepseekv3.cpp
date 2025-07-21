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
    
    ll row_count = rows.size();
    ll col_count = cols.size();
    ll diag1_count = diag1.size();
    ll diag2_count = diag2.size();
    
    ll unsafe1 = row_count * N + col_count * N - row_count * col_count;
    
    ll unsafe2 = 0;
    for (auto d : diag1) {
        ll r1 = max(1LL, 1 + d);
        ll r2 = min(N, N + d);
        ll c1 = max(1LL, 1 - d);
        ll c2 = min(N, N - d);
        if (r1 > r2 || c1 > c2) continue;
        unsafe2 += (r2 - r1 + 1);
    }
    
    for (auto d : diag2) {
        ll r1 = max(1LL, d - N);
        ll r2 = min(N, d - 1);
        ll c1 = max(1LL, d - N);
        ll c2 = min(N, d - 1);
        if (r1 > r2 || c1 > c2) continue;
        unsafe2 += (r2 - r1 + 1);
    }
    
    set<pair<ll, ll>> intersections;
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.count(a - b) || diag2.count(a + b)) {
                intersections.insert({a, b});
            }
        }
    }
    
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 != 0 || (d2 - d1) % 2 != 0) continue;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                intersections.insert({i, j});
            }
        }
    }
    
    ll total_unsafe = unsafe1 + unsafe2 - intersections.size();
    ll total_safe = N * N - total_unsafe;
    
    cout << total_safe << endl;
    
    return 0;
}