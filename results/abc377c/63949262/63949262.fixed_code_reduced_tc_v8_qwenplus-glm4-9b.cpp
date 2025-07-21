#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX_N 1000000000

// Function to check if a position is within the grid bounds
bool is_valid(int x, int y, int N) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

// Function to check if a position is being captured by any existing piece
bool is_captured(vector<vector<int>>& captured, int x, int y) {
    return captured[x][y] == 1;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> captured(N + 1, vector<int>(N + 1, 0));

    // Read all pieces and mark their capture range
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based index

        // Mark the capturing range of the piece
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nx = a + dx, ny = b + dy;
                if (is_valid(nx, ny, N) && !is_captured(captured, nx, ny)) {
                    captured[nx][ny] = 1;
                }
            }
        }
    }

    // Calculate the number of valid empty squares
    long long valid_squares = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (!is_captured(captured, i, j)) {
                valid_squares++;
            }
        }
    }

    cout << valid_squares << endl;

    return 0;
}