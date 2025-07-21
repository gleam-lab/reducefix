#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    set<ll> rows, cols, diag1, diag2, anti_diag1, anti_diag2;

    // Collect all rows, columns, diagonals, and anti-diagonals that are occupied by pieces
    for (auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second);
        diag2.insert(p.first - p.second);
        anti_diag1.insert(p.first - abs(p.second));
        anti_diag2.insert(p.first + abs(p.second));
    }

    ll possible_positions = n * n;

    // Remove occupied rows, columns, and intersections from the count
    possible_positions -= rows.size();
    possible_positions -= cols.size();
    possible_positions -= diag1.size();
    possible_positions -= diag2.size();
    possible_positions -= anti_diag1.size();
    possible_positions -= anti_diag2.size();

    // Output the number of possible positions
    cout << possible_positions << endl;

    return 0;
}