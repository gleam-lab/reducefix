#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> blocked;
    vector<pair<ll, ll>> pieces;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.emplace_back(a, b);
        blocked.emplace(a, b);
    }

    // The 8 possible attack offsets
    vector<pair<ll, ll>> deltas = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // For each piece, compute the squares it can attack and mark them as blocked
    for (auto [x, y] : pieces) {
        for (auto [dx, dy] : deltas) {
            ll nx = x + dx;
            ll ny = y + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                blocked.emplace(nx, ny);
            }
        }
    }

    // Total number of cells: N*N
    // Subtract number of blocked cells
    cout << (N * N - (ll)blocked.size()) << endl;

    return 0;
}