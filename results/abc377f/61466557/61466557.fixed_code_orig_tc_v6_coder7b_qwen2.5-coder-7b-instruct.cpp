#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()

// Function to check if a position is within bounds
bool inBounds(int x, int y, int n) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// Function to calculate the number of valid positions
void solve() {
    ll n, m; cin >> n >> m;
    unordered_set<int> rows, cols, diag1, diag2;
    
    // Store the positions of all pieces
    for(ll i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }
    
    // Calculate the total number of positions
    ll total_positions = n * n;
    
    // Subtract the number of positions occupied by pieces
    total_positions -= rows.size() * n;
    total_positions -= cols.size() * n;
    
    // Add back the intersections of rows and columns since they were subtracted twice
    total_positions += rows.size() * cols.size();
    
    // Iterate over each diagonal and remove invalid positions
    for(auto &pos : diag1) {
        int x = pos / n + 1;
        int y = pos % n + 1;
        if(inBounds(x, y, n)) total_positions--;
    }
    
    for(auto &pos : diag2) {
        int x = pos / n + 1;
        int y = pos % n + 1;
        if(inBounds(x, y, n)) total_positions--;
    }
    
    // Output the result
    cout << total_positions << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}