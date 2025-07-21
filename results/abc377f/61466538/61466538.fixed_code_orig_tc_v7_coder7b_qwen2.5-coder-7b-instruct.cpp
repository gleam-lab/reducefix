#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to check if a position is within bounds
bool inBounds(ll i, ll j, ll n) {
    return 1 <= i && i <= n && 1 <= j && j <= n;
}

// Function to calculate the number of valid positions
ll countValidPositions(ll n, ll m, vector<pair<ll, ll>>& pieces) {
    unordered_set<ll> rows, cols, diagonals1, diagonals2;
    
    // Mark all occupied positions
    for (const auto& [i, j] : pieces) {
        rows.insert(i);
        cols.insert(j);
        diagonals1.insert(i - j);
        diagonals2.insert(i + j);
    }
    
    // Calculate total valid positions
    ll total_valid = n * n;
    
    // Subtract positions attacked by rows
    total_valid -= rows.size() * n;
    
    // Subtract positions attacked by columns
    total_valid -= cols.size() * n;
    
    // Add back positions attacked by both rows and columns (over-subtracted)
    total_valid += rows.size() * cols.size();
    
    // Iterate over each diagonal line
    for (ll d1 : diagonals1) {
        set<pair<ll, ll>> intersections;
        
        // Check all positions on the current diagonal line
        for (const auto& [i, j] : pieces) {
            if (i - j == d1) {
                intersections.insert({i, j});
            }
        }
        
        // Calculate the number of positions on the diagonal line
        ll diag_size = intersections.size();
        
        // Subtract positions attacked by this diagonal line
        total_valid -= diag_size;
        
        // Add back positions attacked by this diagonal line and previously attacked rows/columns
        total_valid += diag_size * min(rows.size(), cols.size());
    }
    
    // Iterate over each anti-diagonal line
    for (ll d2 : diagonals2) {
        set<pair<ll, ll>> intersections;
        
        // Check all positions on the current anti-diagonal line
        for (const auto& [i, j] : pieces) {
            if (i + j == d2) {
                intersections.insert({i, j});
            }
        }
        
        // Calculate the number of positions on the anti-diagonal line
        ll anti_diag_size = intersections.size();
        
        // Subtract positions attacked by this anti-diagonal line
        total_valid -= anti_diag_size;
        
        // Add back positions attacked by this anti-diagonal line and previously attacked rows/columns
        total_valid += anti_diag_size * min(rows.size(), cols.size());
    }
    
    return total_valid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    cout << countValidPositions(n, m, pieces) << endl;
    
    return 0;
}