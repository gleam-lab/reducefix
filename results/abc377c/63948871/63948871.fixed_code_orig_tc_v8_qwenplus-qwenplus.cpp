#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    // Define a hash for pairs to use in unordered_set
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return (static_cast<size_t>(p.first) << 32) | p.second;
        }
    };

    unordered_set<pair<int, int>, pair_hash> attacked_cells;
    vector<pair<int, int>> pieces(M);

    // Directions representing all positions that can attack from a given cell
    const vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};

        // Check and add all cells that this piece can attack
        for (auto& dir : directions) {
            int na = a + dir.first;
            int nb = b + dir.second;
            if (na >= 1 && na <= N && nb >= 1 && nb <= N) {
                attacked_cells.insert({na, nb});
            }
        }
    }

    // Now remove the occupied pieces themselves from available cells
    for (auto& p : pieces) {
        attacked_cells.erase(p); // Ensure own piece is not counted as "attackable"
    }

    // Total cells: N * N
    // Subtract number of attacked cells and the M existing pieces
    int64_t total_cells = static_cast<int64_t>(N) * N;
    int64_t unavailable = attacked_cells.size() + M;

    cout << (total_cells - unavailable) << endl;

    return 0;
}