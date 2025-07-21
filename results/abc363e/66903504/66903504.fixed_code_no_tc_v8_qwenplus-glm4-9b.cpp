#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    cin >> A;

    vector<vector<int>> sink_years(H, vector<int>(W, 0));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    ll total_area = H * W;

    // Initialize the sink_years array
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1 || A[i][j] < A[i][j - 1] || A[i][j] < A[i - 1][j]) {
                sink_years[i][j] = 0;
            }
        }
    }

    // Binary search to find the minimum year when each section will sink
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > 0) {
                int low = 0, high = min(Y, A[i][j]);
                while (low < high) {
                    int mid = (low + high + 1) / 2;
                    bool will_sink = false;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            if (i + di >= 0 && i + di < H && j + dj >= 0 && j + dj < W && A[i][j] > A[i + di][j + dj]) {
                                will_sink = true;
                                break;
                            }
                        }
                        if (will_sink) break;
                    }
                    if (will_sink) high = mid - 1;
                    else low = mid;
                }
                if (low <= Y) sink_years[i][j] = low;
            }
        }
    }

    // Process the sinking each year
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    ll remaining_area = H * W;
    for (int year = 0; year < Y; ++year) {
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (sink_years[i][j] == year) {
                    grid[i][j] = false;
                    remaining_area--;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            if (i + di >= 0 && i + di < H && j + dj >= 0 && j + dj < W) {
                                int ni = i + di, nj = j + dj;
                                if (grid[ni][nj] && A[ni][nj] > year && A[ni][nj] > A[i][j]) {
                                    grid[ni][nj] = false;
                                    remaining_area--;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << remaining_area << '\n';
    }

    return 0;
}