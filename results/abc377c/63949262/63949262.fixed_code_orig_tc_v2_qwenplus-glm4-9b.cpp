#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(N * N);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x - 1, y - 1};  // Convert to 0-indexed
    }

    // Directions a piece can capture
    vector<pair<int, int>> directions = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2},
        {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
    };

    unordered_set<int> attacked_positions;
    for (const auto& piece : pieces) {
        for (const auto& dir : directions) {
            int nx = piece.first + dir.first;
            int ny = piece.second + dir.second;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                attacked_positions.insert(nx * N + ny);
            }
        }
    }

    int empty_positions = N * N - attacked_positions.size();
    cout << empty_positions << endl;

    return 0;
}