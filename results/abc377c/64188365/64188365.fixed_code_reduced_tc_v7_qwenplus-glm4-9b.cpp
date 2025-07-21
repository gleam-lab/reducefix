#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const vector<ii> directions = {
    {2, 1}, {1, 2}, {1, -2}, {-2, 1},
    {-2, -1}, {-1, -2}, {-1, 2}, {2, -1}
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> columns(n);

    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        columns[b].insert(a);
    }

    ll ans = n * n;
    for (ll j = 0; j < n; ++j) {
        for (ll i = 0; i < n; ++i) {
            bool isCaptured = false;
            for (const auto& dir : directions) {
                ll ni = i + dir.first, nj = j + dir.second;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    if (columns[nj].find(ni) != columns[nj].end()) {
                        isCaptured = true;
                        break;
                    }
                }
            }
            if (!isCaptured) {
                ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}