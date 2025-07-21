#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(abs(a - b));
    }

    // Calculate the number of free rows, columns, and diagonals
    ll free_rows = n - rows.size();
    ll free_cols = n - cols.size();
    ll free_diag1 = n - diag1.size();
    ll free_diag2 = n - diag2.size();

    // Subtract the intersections of rows and cols, diag1 and diag2
    ll intersect_rows_cols = rows.size() - diag1.size() - diag2.size();
    ll intersect_diag1_diag2 = diag1.size() - rows.size() - cols.size();
    
    // Calculate the number of free positions
    ll free_positions = free_rows * free_cols;
    
    // Adjust for the intersections
    free_positions -= intersect_rows_cols * n;
    free_positions -= intersect_diag1_diag2 * free_diag1;

    cout << free_positions << endl;
    return 0;
}