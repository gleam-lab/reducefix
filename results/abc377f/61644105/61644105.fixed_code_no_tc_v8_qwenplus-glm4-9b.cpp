#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> rows, cols;
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.push_back({x, y});
        cols.push_back({y, x});
    }

    // Sort and remove duplicates
    sort(rows.begin(), rows.end());
    ll unique_rows = unique(rows.begin(), rows.end()) - rows.begin();
    sort(cols.begin(), cols.end());
    ll unique_cols = unique(cols.begin(), cols.end()) - cols.begin();

    // Calculate the number of empty squares that cannot be captured
    ll empty_squares = n * n - unique_rows - unique_cols;

    // Check for diagonals
    for (ll i = 0; i < m; ++i) {
        for (ll j = i + 1; j < m; ++j) {
            ll r1 = rows[i].first, c1 = rows[i].second;
            ll r2 = rows[j].first, c2 = rows[j].second;

            // Diagonal 1: r1 + c1 = r2 + c2
            if (r1 + c1 == r2 + c2) {
                if ((r1 - c1) % 2 != (r2 - c2) % 2) {
                    // Diagonal crosses an existing piece
                    continue;
                }

                // Calculate the number of pairs on this diagonal
                ll d = abs(r1 - c1);
                ll count1 = upper_bound(rows.begin(), rows.end(), {d, 1}) - rows.begin();
                ll count2 = lower_bound(rows.begin(), rows.end(), {n + d, n}) - rows.begin();
                ll pairs = count2 > count1 ? count2 - count1 : 0;

                empty_squares -= pairs;
            }

            // Diagonal 2: r1 - c1 = r2 - c2
            if (r1 - c1 == r2 - c2) {
                if ((r1 + c1) % 2 != (r2 + c2) % 2) {
                    // Diagonal crosses an existing piece
                    continue;
                }

                // Calculate the number of pairs on this diagonal
                ll d = abs(r1 - c1);
                ll count1 = upper_bound(rows.begin(), rows.end(), {d, 1}) - rows.begin();
                ll count2 = lower_bound(rows.begin(), rows.end(), {n + d, n}) - rows.begin();
                ll pairs = count2 > count1 ? count2 - count1 : 0;

                empty_squares -= pairs;
            }
        }
    }

    cout << empty_squares << endl;
    return 0;
}