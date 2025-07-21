#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    // Use a hash-based set to store attacked or occupied positions
    using ll = long long;
    using pll = pair<ll, ll>;
    struct pair_hash {
        size_t operator()(const pll& p) const {
            return hash<ll>()(p.first * 1000000007 + p.second);
        }
    };
    unordered_set<pll, pair_hash> blocked;

    vector<pll> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        // Block the position itself
        blocked.insert({a, b});
        // Block all positions it can attack
        for (auto [dx, dy] : directions) {
            ll nx = a + dx;
            ll ny = b + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                blocked.insert({nx, ny});
            }
        }
    }

    // Total number of cells is N*N
    // Subtract number of blocked/occupied cells
    cout << N * N - (ll)blocked.size() << endl;

    return 0;
}