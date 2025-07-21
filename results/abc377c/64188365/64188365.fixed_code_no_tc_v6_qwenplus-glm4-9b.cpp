#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    set<pair<ll, ll>> capture_areas;

    // Read the positions of the existing pieces and calculate their capture area
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a - 1, b - 1}; // Adjusting for 0-based indexing
        // Calculate for all 8 possible directions
        for (ll di = -2; di <= 2; di++) {
            for (ll dj = -2; dj <= 2; dj++) {
                if (di == 0 && dj == 0) continue; // Skip the original position
                ll ni = a + di, nj = b + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    capture_areas.insert({ni, nj});
                }
            }
        }
    }

    // Calculate the number of valid positions
    ll valid_positions = n * n - capture_areas.size();

    // Output the result
    cout << valid_positions << endl;

    return 0;
}