#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pll> occupied;
    vector<pair<ll, ll>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    set<pll> unsafe;
    for (auto [x, y] : occupied) {
        for (auto [dx, dy] : moves) {
            ll nx = x + dx;
            ll ny = y + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                unsafe.insert({nx, ny});
            }
        }
    }

    // Remove positions where pieces are already placed since they're not "empty"
    for (auto p : occupied) {
        unsafe.erase(p);
    }

    // Total unsafe empty positions = size of unsafe set
    ll total_cells = N * N;
    ll occupied_count = occupied.size();
    ll unsafe_empty_count = unsafe.size();

    ll result = total_cells - occupied_count - unsafe_empty_count;
    cout << result << endl;

    return 0;
}