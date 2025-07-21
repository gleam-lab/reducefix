#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pll> attacked;
    vector<pll> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        attacked.insert({x, y});
        for (auto [dx, dy] : moves) {
            ll nx = x + dx, ny = y + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N)
                attacked.insert({nx, ny});
        }
    }

    cout << (N * NLL * N * N - (ll)attacked.size()) << "\n";
}