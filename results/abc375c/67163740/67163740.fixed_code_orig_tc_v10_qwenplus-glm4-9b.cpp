#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x, y;
    cin >> n;

    ll total_cost = 0;

    for (ll i = 0; i < n; ++i) {
        cin >> x >> y;
        // Calculate distance from origin to the current point
        total_cost += sqrt(x * x + y * y);
    }

    // Calculate distance from the last point back to the origin
    ll last_x, last_y;
    cin >> last_x >> last_y;
    total_cost += sqrt(last_x * last_x + last_y * last_y);

    cout.precision(20);
    cout << fixed << total_cost << endl;

    return 0;
}