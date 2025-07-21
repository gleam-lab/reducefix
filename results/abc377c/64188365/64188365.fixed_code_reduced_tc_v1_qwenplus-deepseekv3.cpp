#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> attacked;
    set<pair<ll, ll>> existing;

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        existing.insert({a, b});

        // Check all 8 possible attack positions
        vector<pair<ll, ll>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (auto [dx, dy] : directions) {
            ll x = a + dx;
            ll y = b + dy;
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                attacked.insert({x, y});
            }
        }
    }

    // The safe positions are total squares minus (existing squares + attacked squares not existing)
    ll total_squares = n * n;
    ll unsafe_squares = existing.size();

    for (auto pos : attacked) {
        if (existing.find(pos) == existing.end()) {
            unsafe_squares++;
        }
    }

    cout << total_squares - unsafe_squares << endl;
}