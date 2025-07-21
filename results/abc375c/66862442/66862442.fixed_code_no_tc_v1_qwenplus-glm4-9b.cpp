#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u64 = uint64_t;

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    ll curX = 0, curY = 0;
    double total = 0; // Use double to store the total cost

    for (ll i = 0; i < N; ++i) {
        ll x, y;
        cin >> x >> y;

        total += dist(curX, curY, x, y);

        curX = x;
        curY = y;
    }
    total += dist(curX, curY, 0, 0); // Return to the origin

    // Output the total cost with a precision of at least 6 decimal places
    cout << fixed << setprecision(6) << total << '\n';
}