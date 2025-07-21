#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1000;
int H, W, Y;
int grid[MAXN][MAXN];
bool submerged[MAXN][MAXN];
vector<pair<int, int>> neighbors[MAXN * MAXN];

void init_neighbors() {
    int index = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            neighbors[index].push_back({i, j - 1});
            neighbors[index].push_back({i, j + 1});
            neighbors[index].push_back({i - 1, j});
            neighbors[index].push_back({i + 1, j});
            index++;
        }
    }
}

void simulate_rising_sea(int year) {
    queue<int> q;
    for (int i = 0; i < H; ++i) {
        if (grid[i][0] <= year) {
            q.push(i * W);
        }
        if (grid[i][W - 1] <= year) {
            q.push(i * W + W - 1);
        }
    }
    for (int i = 0; i < W; ++i) {
        if (grid[0][i] <= year) {
            q.push(i);
        }
        if (grid[H - 1][i] <= year) {
            q.push((H - 1) * W + i);
        }
    }

    while (!q.empty()) {
        int pos = q.front(); q.pop();
        int x = pos / W;
        int y = pos % W;

        for (auto& p : neighbors[pos]) {
            int nx = p.first;
            int ny = p.second;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (!submerged[nx][ny] && grid[nx][ny] <= year) {
                    q.push(nx * W + ny);
                    submerged[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    init_neighbors();
    memset(submerged, false, sizeof(submerged));

    int total_area = H * W;
    for (int year = 1; year <= Y; ++year) {
        simulate_rising_sea(year);
        // Calculate the area above sea level this year
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!submerged[i][j]) {
                    total_area--;
                }
            }
        }
        cout << total_area << endl;
    }

    return 0;
}