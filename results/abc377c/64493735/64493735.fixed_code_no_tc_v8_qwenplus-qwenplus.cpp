#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
#define v(type) vector<type>
#define s(type) unordered_set<type>
#define p(type1, type2) pair<type1, type2>

// Custom hash for pairs to use in unordered_set
struct PairHash {
    size_t operator()(const pii& p) const {
        return hash<ll>{}(p.first) ^ (hash<ll>{}(p.second) << 32);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    // Use an unordered_set with custom hash to store all forbidden or occupied positions
    unordered_set<pii, PairHash> forbidden;

    // Directions where a piece can attack
    const array<array<ll, 2>, 8> directions = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        forbidden.emplace(a, b);

        // Mark all cells attacked by this piece
        for (const auto& dir : directions) {
            ll na = a + dir[0];
            ll nb = b + dir[1];
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                forbidden.emplace(na, nb);
            }
        }
    }

    // Total grid size is N*N, subtract the number of forbidden squares
    // Note: N can be up to 1e9, so we must use 64-bit integers
    ll total_cells = N * N;
    ll forbidden_count = forbidden.size();

    cout << (total_cells - forbidden_count) << '\n';

    return 0;
}