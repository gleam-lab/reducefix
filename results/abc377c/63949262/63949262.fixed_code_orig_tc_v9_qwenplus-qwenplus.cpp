#include <iostream>
#include <unordered_set>
#include <vector>
#include <tuple>

using namespace std;

// Pair hash function for unordered_set
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 16);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // All positions that are either occupied or can be attacked
    unordered_set<pair<long long, long long>, pair_hash> forbidden;

    vector<pair<long long, long long>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        for (auto [dx, dy] : knight_moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }

    // Total number of cells minus the number of forbidden cells
    cout << (u_int128_t(N) * u_int128_t(N) - forbidden.size()) << "\n";

    return 0;
}