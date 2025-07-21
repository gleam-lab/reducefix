#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool inBounds(const pii &a, const ll n) {
    return 1 <= a.first && a.first <= n && 1 <= a.second && a.second <= n;
}

// Function to count the number of valid positions
ll countValidPositions(ll n, vector<pii> &pieces) {
    set<ll> rows, cols, diagonals1, diagonals2;
    for(auto &p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diagonals1.insert(p.first - p.second);
        diagonals2.insert(p.first + p.second);
    }
    
    ll totalPositions = n * n;
    ll invalidByRow = rows.size() * n;
    ll invalidByCol = cols.size() * n;
    ll invalidByDiagonal1 = diagonals1.size() * n;
    ll invalidByDiagonal2 = diagonals2.size() * n;
    
    ll invalidByBothRowsAndCols = rows.size() * cols.size();
    ll invalidByBothRowsAndDiagonals1 = rows.size() * diagonals1.size();
    ll invalidByBothRowsAndDiagonals2 = rows.size() * diagonals2.size();
    ll invalidByBothColsAndDiagonals1 = cols.size() * diagonals1.size();
    ll invalidByBothColsAndDiagonals2 = cols.size() * diagonals2.size();
    
    ll invalidByAllFour = invalidByRowsAndCols + invalidByRowsAndDiagonals1 + 
                          invalidByRowsAndDiagonals2 + invalidByColsAndDiagonals1 +
                          invalidByColsAndDiagonals2 - 
                          (invalidByBothRowsAndCols + invalidByBothRowsAndDiagonals1 + 
                           invalidByBothRowsAndDiagonals2 + invalidByBothColsAndDiagonals1 +
                           invalidByBothColsAndDiagonals2) +
                          (invalidByBothRowsAndCols * invalidByBothRowsAndCols +
                           invalidByBothRowsAndCols * invalidByBothRowsAndDiagonals1 +
                           invalidByBothRowsAndCols * invalidByBothRowsAndDiagonals2 +
                           invalidByBothRowsAndCols * invalidByBothColsAndDiagonals1 +
                           invalidByBothRowsAndCols * invalidByBothColsAndDiagonals2 +
                           invalidByBothRowsAndDiagonals1 * invalidByBothRowsAndDiagonals1 +
                           invalidByBothRowsAndDiagonals1 * invalidByBothRowsAndDiagonals2 +
                           invalidByBothRowsAndDiagonals1 * invalidByBothColsAndDiagonals1 +
                           invalidByBothRowsAndDiagonals1 * invalidByBothColsAndDiagonals2 +
                           invalidByBothRowsAndDiagonals2 * invalidByBothRowsAndDiagonals2 +
                           invalidByBothRowsAndDiagonals2 * invalidByBothColsAndDiagonals1 +
                           invalidByBothRowsAndDiagonals2 * invalidByBothColsAndDiagonals2 +
                           invalidByBothColsAndDiagonals1 * invalidByBothColsAndDiagonals1 +
                           invalidByBothColsAndDiagonals1 * invalidByBothColsAndDiagonals2 +
                           invalidByBothColsAndDiagonals2 * invalidByBothColsAndDiagonals2) -
                          (invalidByAllFour * invalidByAllFour);
                          
    ll validPositions = totalPositions - invalidByAllFour;
    return validPositions;
}

// Main function to solve the problem
void solve() {
    ll n, m; cin >> n >> m;
    vector<pii> pieces(m);
    for(auto &p : pieces) { cin >> p.first >> p.second; }
    
    ll result = countValidPositions(n, pieces);
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}