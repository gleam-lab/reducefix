#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int dx[9] = {2, 2, 1, 1, -1, -1, -2, -2, 0};
const int dy[9] = {1, -1, 2, -2, 2, -2, 1, -1, 0};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> field(N, vector<int>(N, 1)); // Using 1 for True (available)
    set<pair<int, int>> occupied;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        field[a - 1][b - 1] = 0; // Mark the cell as occupied (use 0 for False)
        occupied.insert({a - 1, b - 1});
    }

    // Check for all occupied cells
    for (const auto& p : occupied) {
        int x = p.first;
        int y = p.second;
        // Check for each possible capture direction
        for (int k = 1; k <= 8; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && field[nx][ny] == 1) {
                field[nx][ny] = 0; // Mark as occupied
                occupied.insert({nx, ny});
            }
        }
    }

    // Count available cells
    int available_cells = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field[i][j] == 1) {
                available_cells++;
            }
        }
    }

    cout << available_cells << endl;
    return 0;
}