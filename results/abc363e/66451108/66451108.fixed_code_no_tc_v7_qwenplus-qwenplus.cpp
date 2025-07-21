#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define endl '\n'

const int MAX_Y = 100000 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int H, W, Y;
vector<vector<int>> grid;
vector<vector<bool>> vis;
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
int remaining[MAX_Y];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> Y;
    grid.assign(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];

    vis.assign(H, vector<bool>(W, false));

    // Initialize the queue with all boundary cells (sea level starts at 0)
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                if (!vis[i][j]) {
                    vis[i][j] = true;
                    pq.push({grid[i][j], {i, j}});
                }
            }
        }
    }

    int totalLand = H * W;
    int year = 1;
    remaining[0] = totalLand;

    while (!pq.empty()) {
        auto [height, pos] = pq.top();
        pq.pop();

        while (year <= Y && year < height) {
            remaining[year] = totalLand;
            ++year;
        }

        if (year > Y) break;

        do {
            remaining[year] = totalLand;
            ++year;
        } while (year <= Y && height >= year);

        --year;
        remaining[year] = max(remaining[year], totalLand - 1);
        totalLand--;
    }

    while (year <= Y) {
        remaining[year] = totalLand;
        ++year;
    }

    for (int i = 1; i <= Y; ++i)
        cout << remaining[i] << endl;

    return 0;
}