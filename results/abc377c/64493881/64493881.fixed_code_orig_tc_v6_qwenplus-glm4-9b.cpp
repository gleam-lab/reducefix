#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> captured(N + 4, vector<int>(N + 4, 0)); // Use N+4 to avoid boundary issues
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        // Mark the cells that can be captured by the piece at (x, y)
        captured[x + 2][y + 1] = 1;
        captured[x + 1][y + 2] = 1;
        captured[x - 1][y + 2] = 1;
        captured[x - 2][y + 1] = 1;
        captured[x - 2][y - 1] = 1;
        captured[x - 1][y - 2] = 1;
        captured[x + 1][y - 2] = 1;
        captured[x + 2][y - 1] = 1;
    }

    int empty_cells = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            // If the cell is not captured, it is an empty cell
            if (captured[i][j] == 0) {
                empty_cells++;
            }
        }
    }

    cout << empty_cells << endl;
    return 0;
}