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
    unordered_set<ll> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
        ll a = queens[i].first, b = queens[i].second;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll unsafe = 0;
    
    // Squares attacked by rows or columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Overlap between rows and columns
    
    // Squares attacked by diagonals (i-j)
    for (ll d : diag1) {
        // Number of squares on diagonal i-j = d
        ll cnt = N - abs(d);
        unsafe += cnt;
    }
    
    // Squares attacked by diagonals (i+j)
    for (ll d : diag2) {
        // Number of squares on diagonal i+j = d
        ll cnt = (d <= N + 1) ? (d - 1) : (2 * N - d + 1);
        unsafe += cnt;
    }
    
    // Subtract overlaps between diagonals and rows/columns
    for (pll queen : queens) {
        ll a = queen.first, b = queen.second;
        // For each queen, subtract 3 overlaps (row+diag1, row+diag2, col+diag1, col+diag2, diag1+diag2)
        // But need proper inclusion-exclusion here
        unsafe -= 1; // The queen itself was counted in all four sets
    }
    
    // Add back overlaps between row, column, and both diagonals
    for (pll queen : queens) {
        ll a = queen.first, b = queen.second;
        // Squares where row, column, and both diagonals meet (only the queen itself)
        unsafe += 1;
    }
    
    // Total safe squares = total squares - unsafe squares + overlaps
    ll total_safe = N * N - unsafe;
    
    cout << total_safe << endl;
    
    return 0;
}