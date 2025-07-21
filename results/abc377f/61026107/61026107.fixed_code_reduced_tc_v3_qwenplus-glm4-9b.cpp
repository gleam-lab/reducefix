#include <iostream>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    set<ll> row, col, diag1, diag2;
    for (ll i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        row.insert(a);
        col.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Calculate the number of empty cells that can't be captured by any existing piece
    ll ans = n * n;

    // Subtract cells that are in any of the affected rows, columns, or diagonals
    for (auto r : row) ans -= max(0LL, n - r + 1);
    for (auto c : col) ans -= max(0LL, n - c + 1);
    for (auto d : diag1) ans -= max(0LL, n - (2 * d - 2 * n) + 1);
    for (auto d : diag2) ans -= max(0LL, n - (2 * n - 2 * d) + 1);

    // Output the result
    cout << ans << '\n';

    return 0;
}