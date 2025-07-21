#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols;
    map<ll, ll> diag1, diag2; // diag1: i-j, diag2: i+j
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1[a - b]++;
        diag2[a + b]++;
    }
    
    ll total_squares = N * N;
    ll attacked = 0;
    
    // Attacked by rows or columns
    attacked += rows.size() * N + cols.size() * N - rows.size() * cols.size();
    
    // Attacked by diagonals (i-j or i+j)
    for (auto &p : diag1) {
        ll d = p.first;
        ll count = p.second;
        // Calculate the number of squares in the diagonal i-j = d
        ll i_min = max(1LL, 1 + d);
        ll i_max = min(N, N + d);
        if (i_min > i_max) continue;
        ll squares_in_diag = i_max - i_min + 1;
        attacked += squares_in_diag;
    }
    
    for (auto &p : diag2) {
        ll s = p.first;
        ll count = p.second;
        // Calculate the number of squares in the anti-diagonal i+j = s
        ll i_min = max(1LL, s - N);
        ll i_max = min(N, s - 1);
        if (i_min > i_max) continue;
        ll squares_in_anti_diag = i_max - i_min + 1;
        attacked += squares_in_anti_diag;
    }
    
    // Subtract overlaps between rows/cols and diagonals/anti-diagonals
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) || diag2.count(r + c)) {
                attacked--;
            }
        }
    }
    
    // Subtract overlaps between diagonals and anti-diagonals
    for (auto &p1 : diag1) {
        ll d = p1.first;
        for (auto &p2 : diag2) {
            ll s = p2.first;
            // Solve i - j = d and i + j = s
            ll i = (d + s) / 2;
            ll j = (s - d) / 2;
            if ((d + s) % 2 != 0 || (s - d) % 2 != 0) continue;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                attacked--;
            }
        }
    }
    
    // Add overlaps among rows, cols, diagonals, anti-diagonals (if any)
    // Here, overlaps are considered if a square is covered by all four conditions
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                attacked++;
            }
        }
    }
    
    ll safe_squares = total_squares - attacked;
    cout << safe_squares << endl;
    
    return 0;
}