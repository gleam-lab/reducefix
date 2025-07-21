#include <bits/stdc++.h>
using namespace std;

// Custom hash for pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()((1LL << 32) * p.first + p.second);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, PairHash> occupied, attacked;

    // All 8 possible attack positions from a knight move pattern
    vector<pair<int, int>> offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        occupied.insert({a, b});
        for (auto [dx, dy] : offsets) {
            int x = a + dx;
            int y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                attacked.insert({x, y});
            }
        }
    }

    // Remove occupied cells from attacked set
    for (auto& pos : occupied) {
        attacked.erase(pos);
    }

    // Total cells: N^2
    // Available cells = total - occupied_count - attacked_count
    long long total_cells = 1LL * N * N;
    long long used_cells = occupied.size() + attacked.size();

    cout << total_cells - used_cells << "\n";

    return 0;
}