#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    unordered_set<ll> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll total = N * N;
    
    ll rows_count = rows.size();
    ll cols_count = cols.size();
    ll diag1_count = diag1.size();
    ll diag2_count = diag2.size();
    
    total -= rows_count * N + cols_count * N;
    
    for (auto d : diag1) {
        ll min_sum = 2;
        ll max_sum = 2 * N;
        if (d < min_sum || d > max_sum) continue;
        ll cnt = min(d - 1, 2 * N - d + 1);
        total -= cnt;
    }
    
    for (auto d : diag2) {
        ll min_diff = -(N - 1);
        ll max_diff = N - 1;
        if (d < min_diff || d > max_diff) continue;
        ll cnt = N - abs(d);
        total -= cnt;
    }
    
    total += rows_count * cols_count;
    
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.find(r + c) != diag1.end()) {
                total++;
            }
            if (diag2.find(r - c) != diag2.end()) {
                total++;
            }
        }
    }
    
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll x = (d1 + d2) / 2;
            ll y = (d1 - d2) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (rows.find(x) != rows.end() || cols.find(y) != cols.end()) {
                    total++;
                }
            }
        }
    }
    
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.find(r + c) != diag1.end() && diag2.find(r - c) != diag2.end()) {
                total--;
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}