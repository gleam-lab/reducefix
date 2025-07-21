#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int h, w, y;
vector<vector<int>> grid;
vector<vector<bool>> vis;
vector<vector<int>> levels;

void init() {
    grid.resize(h, vector<int>(w));
    vis.resize(h, vector<bool>(w, false));
    levels.resize(y + 1, vector<int>(h * w + 1, 0));
}

void input() {
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!vis[i][j]) {
                levels[1][grid[i][j]]++;
            }
        }
    }
}

void process() {
    for (int year = 2; year <= y; ++year) {
        for (int height = 1; height <= h * w; ++height) {
            if (levels[year - 1][height] > 0) {
                levels[year][height]++;
                levels[year][height - 1] += levels[year - 1][height];
                levels[year][height + 1] += levels[year - 1][height];
            }
        }
    }
}

void output() {
    for (int year = 1; year <= y; ++year) {
        cout << levels[year][h * w] << endl;
    }
}

int main() {
    close;
    init();
    input();
    process();
    output();
    return 0;
}