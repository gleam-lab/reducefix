#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = LLONG_MAX / 2;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll n, m;
    cin >> n >> m;

    unordered_set<pll> pieces;
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        pieces.insert({x, y});
    }

    ll count = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            bool valid = true;
            for (ll dx = -2; dx <= 2; ++dx) {
                for (ll dy = -2; dy <= 2; ++dy) {
                    if (abs(dx) == abs(dy)) continue;
                    ll nx = i + dx, ny = j + dy;
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && pieces.count({nx, ny})) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }
            if (valid) count++;
        }
    }

    cout << count << endl;

    return 0;
}