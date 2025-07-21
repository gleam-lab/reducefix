#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> captured_cells;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        // Add the current piece
        captured_cells.insert({x, y});

        // Mark all cells that can be captured by the piece at (x, y)
        int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
        int dy[] = {1, -1, 2, 2, 1, -1, -2, -2};
        for (int j = 0; j < 8; ++j) {
            int nx = x + dx[j], ny = y + dy[j];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                captured_cells.insert({nx, ny});
            }
        }
    }

    // Calculate the number of cells that can be filled without being captured
    long long total_cells = N * N;
    long long captured_count = captured_cells.size();
    long long safe_cells = total_cells - captured_count;

    cout << safe_cells << endl;

    return 0;
}