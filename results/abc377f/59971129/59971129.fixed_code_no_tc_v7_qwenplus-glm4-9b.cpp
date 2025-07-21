#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    set<ll> rows, cols, diag1, diag2;
    
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(abs(a - b));
    }
    
    // Calculate the number of empty rows, columns, and squares that can't be captured
    ll free_rows = n - rows.size();
    ll free_cols = n - cols.size();
    ll free_diag1 = n - diag1.size();
    ll free_diag2 = n - diag2.size();
    
    // Calculate the overlapping regions
    set<pair<ll, ll>> intersections;
    for (ll x : rows) {
        for (ll y : cols) {
            intersections.insert({x, y});
        }
    }
    for (ll x : rows) {
        for (ll y : diag1) {
            if (x + y <= n) {
                intersections.insert({x, y});
            }
        }
    }
    for (ll x : rows) {
        for (ll y : diag2) {
            if (x + y <= n) {
                intersections.insert({x, y});
            }
        }
    }
    
    ll free_cells = (n * n) - intersections.size();
    
    // Calculate the final answer
    ll answer = free_rows * free_cols * free_diag1 * free_diag2 * free_cells;
    
    cout << answer << endl;
    
    return 0;
}