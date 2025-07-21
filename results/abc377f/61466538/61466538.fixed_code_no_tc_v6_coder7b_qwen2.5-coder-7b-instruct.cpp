#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to check if a position is within bounds
bool inBounds(ll x, ll y, ll n) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// Main function to solve the problem
void solve() {
    ll n, m; cin >> n >> m;
    unordered_set<ll> rows, cols, diagonals1, diagonals2;
    
    // Store positions of existing pieces
    for(ll i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diagonals1.insert(x - y);
        diagonals2.insert(x + y);
    }
    
    // Calculate the total number of empty squares
    ll total_empty_squares = n * n;
    
    // Subtract the squares occupied by pieces in rows and columns
    total_empty_squares -= rows.size() * n;
    total_empty_squares -= cols.size() * n;
    
    // Add back the squares that were subtracted twice (intersections of rows and columns)
    total_empty_squares += rows.size() * cols.size();
    
    // Subtract the squares occupied by pieces in diagonals
    for(ll d : diagonals1) {
        total_empty_squares -= min((ll)n, abs(d) + 1);
    }
    for(ll d : diagonals2) {
        total_empty_squares -= min((ll)n, abs(d) + 1);
    }
    
    // Output the result
    cout << total_empty_squares << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}