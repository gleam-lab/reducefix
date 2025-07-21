#include <iostream>
#include <unordered_set>
#include <vector>
#include <tuple>

using namespace std;

// Custom hash for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 16);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    using ll = long long;
    unordered_set<pair<ll, ll>, pair_hash> occupied;

    vector<pair<ll, ll>> deltas = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        for (auto [dx, dy] : deltas) {
            ll x = a + dx;
            ll y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                occupied.insert({x, y});
            }
        }
    }

    // Total possible positions = N*N
    // Subtract already occupied and attacked positions
    cout << (N * N - (ll)occupied.size()) << "\n";

    return 0;
}