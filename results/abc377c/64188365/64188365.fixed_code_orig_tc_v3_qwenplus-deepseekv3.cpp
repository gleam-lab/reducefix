#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> attacked;
    set<pair<ll, ll>> pieces;

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--; // converting to 0-based index for easier calculations
        pieces.insert({a, b});
        attacked.insert({a, b});

        // All 8 possible attack moves
        vector<pair<ll, ll>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (auto [x, y] : moves) {
            if (x >= 0 && x < n && y >= 0 && y < n) {
                attacked.insert({x, y});
            }
        }
    }

    // Total safe positions = total cells - attacked positions (including pieces)
    cout << n * n - attacked.size() << endl;
}