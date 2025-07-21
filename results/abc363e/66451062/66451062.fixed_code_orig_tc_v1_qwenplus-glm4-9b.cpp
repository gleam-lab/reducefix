#include <bits/stdc++.h>
using namespace std;
#define int long long

int H, W, Y;
vector<vector<int>> A;
bool flood[1001][1001];
set<pair<int, int>> flooded;

void process_flood(int x, int y) {
    if (x < 0 || x >= H || y < 0 || y >= W || flood[x][y] || A[x][y] <= Y) return;
    flood[x][y] = true;
    flooded.insert({x, y});
    process_flood(x + 1, y);
    process_flood(x - 1, y);
    process_flood(x, y + 1);
    process_flood(x, y - 1);
}

int main() {
    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    for (int year = 1; year <= Y; year++) {
        memset(flood, false, sizeof(flood));
        flooded.clear();

        // Initially flood the cells at the edges of the island
        for (int j = 0; j < W; j++) {
            process_flood(0, j);
            process_flood(H - 1, j);
        }
        for (int i = 0; i < H; i++) {
            process_flood(i, 0);
            process_flood(i, W - 1);
        }

        // Calculate the remaining area
        long long remaining_area = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!flood[i][j]) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}