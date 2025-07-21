#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> pieces(m);
    set<ll> rows, cols;

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
    }

    set<pair<ll, ll>> capture_sets;
    set<pair<ll, ll>> diagonals_1, diagonals_2;

    for (ll i = 0; i < m; ++i) {
        ll r = pieces[i].first;
        ll c = pieces[i].second;
        for (ll j = 1; j <= n; ++j) {
            capture_sets.insert({r, j});
            capture_sets.insert({j, c});
            capture_sets.insert({r + c, j});
            capture_sets.insert({r - c, j});
        }
        diagonals_1.insert({r + c, r - c});
        diagonals_2.insert({r + c + 1, r - c - 1});
    }

    // Removing captured rows and columns
    for (ll r : rows) {
        for (ll c : capture_sets) {
            if (c.first == r) {
                capture_sets.erase(c);
            }
        }
    }
    for (ll c : cols) {
        for (ll r : capture_sets) {
            if (r.second == c) {
                capture_sets.erase(r);
            }
        }
    }

    // Removing captured diagonals
    set<pair<ll, ll>> valid_diag_1, valid_diag_2;
    for (ll d : diagonals_1) {
        ll r = d.first;
        ll c = d.second;
        if (r > 0 && c > 0 && r <= n && c <= n && rows.count(r) == 0 && cols.count(c) == 0) {
            valid_diag_1.insert(d);
        }
    }
    for (ll d : diagonals_2) {
        ll r = d.first;
        ll c = d.second;
        if (r > 0 && c < 0 && r <= n && c >= 1 && rows.count(r) == 0 && cols.count(c) == 0) {
            valid_diag_2.insert(d);
        }
    }

    // Calculate the number of valid positions
    ll ans = n * n - capture_sets.size();
    for (ll d : valid_diag_1) {
        ans -= n - 2;
    }
    for (ll d : valid_diag_2) {
        ans -= n - 2;
    }

    cout << ans << endl;

    return 0;
}