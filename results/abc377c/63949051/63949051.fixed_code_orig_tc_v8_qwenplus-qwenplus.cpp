#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

// Custom hash for pair<int, int>
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return ((size_t)(p.first) << 32) | (p.second);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    unordered_set<pair<int, int>, pair_hash> attacked;

    // All positions that can be attacked by existing pieces
    for (auto& p : pieces) {
        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int nx = p.first + dx[k];
            int ny = p.second + dy[k];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked.insert({nx, ny});
            }
        }
    }

    // Remove all original piece positions from attacked set if they are there
    for (auto& p : pieces) {
        attacked.erase(p);
    }

    // Total number of cells is N*N
    // Subtract the number of attacked and occupied positions
    long long total_cells = (long long)N * (long long)N;
    long long taken = (long long)attacked.size() + M;

    cout << total_cells - taken << "\n";

    return 0;
}