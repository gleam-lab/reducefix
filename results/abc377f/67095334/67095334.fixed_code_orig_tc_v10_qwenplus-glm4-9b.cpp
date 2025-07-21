#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    set<pair<ll, ll>> capturable;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;

        // Rows and columns
        capturable.insert({a, n});  // All in row a
        capturable.insert({n, b});  // All in column b

        // Diagonals
        ll d1 = a + b;
        ll d2 = a - b;
        capturable.insert({min(d1, n), max(d1, 0)});  // Diagonal d1
        capturable.insert({min(d2, n), max(d2, 0)});  // Diagonal d2
    }

    // Count all capturable squares
    ll capturable_count = 0;
    for (auto& p : capturable) {
        capturable_count += (p.second - p.first + 1);
    }

    // Total squares minus capturable squares
    ll total_squares = n * n;
    ll empty_squares = total_squares - capturable_count;

    cout << empty_squares << endl;

    return 0;
}