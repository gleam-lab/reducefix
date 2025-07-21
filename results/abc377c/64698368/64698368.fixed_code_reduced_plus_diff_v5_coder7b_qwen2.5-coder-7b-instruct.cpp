#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::unordered_set<std::pair<int, int>> occupied;

    // Directions for capturing moves
    std::vector<std::pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (int i = 0; i < M; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y; // Convert to zero-based index

        for (auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                occupied.insert({nx, ny});
            }
        }
    }

    std::cout << N * N - occupied.size() << '\n';
    return 0;
}