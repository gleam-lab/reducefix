#include <bits/stdc++.h>
using namespace std;

// Custom hash for pair<long long, long long>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 16);
    }
};

int main() {
    long long N, M;
    cin >> N >> M;

    unordered_set<pair<long long, long long>, pair_hash> occupied;
    unordered_set<pair<long long, long long>, pair_hash> attacked;

    // Possible knight moves (relative positions)
    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.emplace(a, b);

        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.emplace(x, y);
            }
        }
    }

    // Remove positions that are already occupied from attacked set
    for (auto& pos : occupied) {
        attacked.erase(pos);
    }

    // Total valid positions = total cells - (occupied + attacked)
    long long total_cells = N * N;
    long long blocked = occupied.size() + attacked.size();
    cout << total_cells - blocked << endl;

    return 0;
}