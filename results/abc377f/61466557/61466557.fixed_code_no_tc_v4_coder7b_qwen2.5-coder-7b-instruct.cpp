#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()

// Function to check if a position is within bounds
bool inBounds(int x, int y, int n) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// Main function to solve the problem
void solve() {
    ll n, m; 
    re(n, m);
    vector<pii> q(m); 
    FOR(i, 0, m) { 
        re(q[i].first, q[i].second); 
    }
    
    // Sets to store occupied rows, columns, and diagonals
    set<int> row, col, d1, d2;
    for(auto [i, j] : q) {
        row.insert(i); 
        col.insert(j); 
        d1.insert(i - j); 
        d2.insert(i + j);
    }
    
    // Calculate the total number of empty squares
    ll ans = n * n;
    ans -= 1LL * row.size() * n; 
    ans -= 1LL * col.size() * n; 
    ans += 1LL * row.size() * col.size(); 

    // Handle diagonal captures
    for(auto &d : d1) {
        ll cnt = min(n, abs(d));
        ans -= cnt;
    }
    for(auto &d : d2) {
        ll cnt = min(n, abs(d));
        ans -= cnt;
    }
    
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}