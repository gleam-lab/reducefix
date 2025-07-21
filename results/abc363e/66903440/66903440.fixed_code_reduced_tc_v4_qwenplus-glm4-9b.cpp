#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initial sea level is 0
    int sea_level = 0;
    int remaining_area = H * W;
    queue<pair<int, int>> q;

    // Initialize the queue with the sections that are on the borders
    for (int i = 0; i < H; ++i) {
        if (A[i][0] <= sea_level || A[i][W - 1] <= sea_level) {
            q.push({i, 0});
            q.push({i, W - 1});
            if (A[i][0] <= sea_level) remaining_area -= 1;
            if (A[i][W - 1] <= sea_level) remaining_area -= 1;
        }
    }
    for (int j = 0; j < W; ++j) {
        if (A[0][j] <= sea_level || A[H - 1][j] <= sea_level) {
            q.push({0, j});
            q.push({H - 1, j});
            if (A[0][j] <= sea_level) remaining_area -= 1;
            if (A[H - 1][j] <= sea_level) remaining_area -= 1;
        }
    }

    // Process the queue for Y years
    while (sea_level < Y && !q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            auto [i, j] = q.front();
            q.pop();

            // Check neighbors
            if (i > 0 && A[i - 1][j] <= ++sea_level) q.push({i - 1, j});
            if (i < H - 1 && A[i + 1][j] <= sea_level) q.push({i + 1, j});
            if (j > 0 && A[i][j - 1] <= sea_level) q.push({i, j - 1});
            if (j < W - 1 && A[i][j + 1] <= sea_level) q.push({i, j + 1});

            // Update the remaining area
            if (A[i][j] <= sea_level) {
                remaining_area--;
                if (i > 0 && j > 0 && A[i - 1][j - 1] <= sea_level) {
                    remaining_area--;
                    A[i - 1][j - 1] = sea_level + 1;
                }
                if (i > 0 && j < W - 1 && A[i - 1][j + 1] <= sea_level) {
                    remaining_area--;
                    A[i - 1][j + 1] = sea_level + 1;
                }
                if (i < H - 1 && j > 0 && A[i + 1][j - 1] <= sea_level) {
                    remaining_area--;
                    A[i + 1][j - 1] = sea_level + 1;
                }
                if (i < H - 1 && j < W - 1 && A[i + 1][j + 1] <= sea_level) {
                    remaining_area--;
                    A[i + 1][j + 1] = sea_level + 1;
                }
            }
        }
    }

    // Output the remaining area after Y years
    for (int i = 0; i < Y; ++i) {
        cout << remaining_area << endl;
    }

    return 0;
}