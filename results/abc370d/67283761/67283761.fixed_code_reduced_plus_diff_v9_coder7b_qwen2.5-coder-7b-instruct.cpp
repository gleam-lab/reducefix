#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <unordered_set>
using namespace std;

struct Bomb {
    int r, c;
    Bomb(int _r, int _c) : r(_r), c(_c) {}
};

class Solution {
public:
    static const int dx[4] = {0, 0, 1, -1};
    static const int dy[4] = {1, -1, 0, 0};

    void simulateBombs(vector<vector<bool>>& grid, int Q, vector<Bomb>& bombs) {
        unordered_set<long long> visited;
        for (const auto& bomb : bombs) {
            if (!grid[bomb.r][bomb.c]) continue;
            queue<Bomb> q;
            q.push(bomb);
            while (!q.empty()) {
                Bomb current = q.front();
                q.pop();
                long long pos = ((long long)current.r << 32) | current.c;
                if (visited.count(pos)) continue;
                visited.insert(pos);
                for (int d = 0; d < 4; ++d) {
                    int x = current.r + dx[d], y = current.c + dy[d];
                    while (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size()) {
                        pos = ((long long)x << 32) | y;
                        if (visited.count(pos)) break;
                        if (grid[x][y]) {
                            grid[x][y] = false;
                            q.push({x, y});
                        } else break;
                        x += dx[d], y += dy[d];
                    }
                }
            }
        }
    }

    static int countRemainingWalls(const vector<vector<bool>>& grid) {
        return accumulate(grid.begin(), grid.end(), 0,
                          [](int sum, const vector<bool>& row) {
                              return sum + count(row.begin(), row.end(), true);
                          });
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H, vector<bool>(W, true));
    vector<Solution::Bomb> bombs(Q);

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        bombs[i] = {r, c};
    }

    Solution::simulateBombs(grid, Q, bombs);
    cout << Solution::countRemainingWalls(grid) << '\n';

    return 0;
}