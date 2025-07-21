#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

#define fi first
#define se second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    set<pll> attacked;
    vector<pll> pieces(M);

    // Knight-like attack patterns
    const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int k = 0; k < M; ++k) {
        ll x, y;
        cin >> x >> y;
        pieces[k] = {x, y};

        // This set will store positions that are either occupied or under attack
        attacked.insert({x, y});

        for (int i = 0; i < 8; ++i) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked.insert({nx, ny});
            }
        }
    }

    // The result is total cells minus the attacked/occupied cells
    ll ans = (ll)N * N - (ll)attacked.size();
    cout << ans << "\n";

    return 0;
}