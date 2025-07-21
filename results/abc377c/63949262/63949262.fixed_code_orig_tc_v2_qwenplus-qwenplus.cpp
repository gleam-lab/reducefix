#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

// Define a custom hash for pairs to be used in unordered_set
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 16);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Directions where existing pieces can attack
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    unordered_set<pair<long long, long long>, pair_hash> attacked_cells;
    unordered_set<pair<long long, long long>, pair_hash> occupied_cells;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied_cells.emplace(a, b);
        for (auto& dir : directions) {
            long long ni = a + dir.first;
            long long nj = b + dir.second;
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                attacked_cells.emplace(ni, nj);
            }
        }
    }

    // Remove cells that are already occupied by existing pieces
    for (auto& cell : occupied_cells) {
        attacked_cells.erase(cell);
    }

    // Total available safe empty cells
    unsigned __int128 total_cells = (__int128)(N) * N;
    cout << total_cells - attacked_cells.size() - occupied_cells.size() << endl;

    return 0;
}