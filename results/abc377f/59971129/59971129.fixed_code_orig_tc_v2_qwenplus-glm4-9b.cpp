#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        --pieces[i].first;
        --pieces[i].second;
    }
    
    // Sets to track captured rows, columns, and diagonals
    set<ll> captured_rows, captured_columns;
    set<pair<ll, ll>, greater<pair<ll, ll>>> captured_diagonals; // (i+j, i-j)
    
    // Mark captured rows, columns, and diagonals
    for (auto& piece : pieces) {
        captured_rows.insert(piece.first);
        captured_columns.insert(piece.second);
        captured_diagonals.insert({piece.first + piece.second, piece.first - piece.second});
    }
    
    // Calculate the number of squares not captured by rows
    ll free_squares = n * n;
    for (ll row : captured_rows) {
        free_squares -= n;
    }
    
    // Calculate the number of squares not captured by columns
    for (ll col : captured_columns) {
        free_squares -= n;
    }
    
    // Calculate the number of squares not captured by diagonals
    for (auto& diag : captured_diagonals) {
        ll x = diag.first;
        ll y = diag.second;
        // Number of squares on the diagonal from (0,0) to (x,y)
        ll count = min({x + 1, y + 1, n - x, n - y});
        free_squares -= count;
    }
    
    // Output the number of free squares
    cout << free_squares << endl;
    
    return 0;
}