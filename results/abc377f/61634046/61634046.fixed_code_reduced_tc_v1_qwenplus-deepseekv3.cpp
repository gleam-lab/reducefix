#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i + j, diag2: i - j
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll total = N * N;
    ll forbidden = 0;
    
    // Rows and columns
    forbidden += rows.size() * N;
    forbidden += cols.size() * N;
    forbidden -= rows.size() * cols.size();
    
    // Diagonals (i + j = k)
    for (ll d : diag1) {
        ll cnt = 0;
        // i ranges from max(1, d - N) to min(N, d - 1)
        ll i_min = max(1LL, d - N);
        ll i_max = min(N, d - 1);
        if (i_min <= i_max) {
            cnt = i_max - i_min + 1;
        }
        forbidden += cnt;
    }
    
    // Diagonals (i - j = k)
    for (ll d : diag2) {
        ll cnt = 0;
        // i ranges from max(1, 1 + d) to min(N, N + d)
        ll i_min = max(1LL, 1 + d);
        ll i_max = min(N, N + d);
        if (i_min <= i_max) {
            cnt = i_max - i_min + 1;
        }
        forbidden += cnt;
    }
    
    // Subtract overlaps between rows/columns and diagonals
    for (ll r : rows) {
        for (ll d : diag1) {
            ll j = d - r;
            if (j >= 1 && j <= N && cols.count(j)) {
                forbidden--;
            }
        }
        for (ll d : diag2) {
            ll j = r - d;
            if (j >= 1 && j <= N && cols.count(j)) {
                forbidden--;
            }
        }
    }
    
    // Subtract overlaps between diagonals
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            // Solve i + j = d1, i - j = d2
            ll i = (d1 + d2) / 2;
            ll j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.count(i) || cols.count(j)) {
                    forbidden--;
                }
            }
        }
    }
    
    // Add back overlaps between rows, columns, and diagonals if they were subtracted twice
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                forbidden++;
            }
        }
    }
    
    ll safe = total - forbidden;
    cout << safe << endl;
    
    return 0;
}