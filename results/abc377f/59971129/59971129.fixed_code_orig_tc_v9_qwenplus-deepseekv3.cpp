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
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll forbidden = 0;
    
    // For rows and columns
    ll row_count = rows.size();
    ll col_count = cols.size();
    forbidden += row_count * N + col_count * N - row_count * col_count;
    
    // For diagonals (i + j)
    ll diag1_count = diag1.size();
    for (auto d : diag1) {
        ll upper = min(d - 1, N);
        ll lower = max(d - N, 1LL);
        forbidden += (upper - lower + 1);
    }
    
    // For anti-diagonals (i - j)
    ll diag2_count = diag2.size();
    for (auto d : diag2) {
        ll lower_i = max(1LL, 1 + d);
        ll upper_i = min(N, N + d);
        forbidden += (upper_i - lower_i + 1);
    }
    
    // Subtract overlaps between rows/columns and diagonals/anti-diagonals
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.find(a + b) != diag1.end() || diag2.find(a - b) != diag2.end()) {
                forbidden--;
            }
        }
    }
    
    // Subtract overlaps between diagonals and anti-diagonals
    // This is complex, but for M <= 1e3, we can check all pairs
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll i = (d1 + d2) / 2;
            ll j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                forbidden--;
            }
        }
    }
    
    // Total safe positions
    ll total = N * N - forbidden;
    cout << total << endl;
    
    return 0;
}