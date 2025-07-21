#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));
    queue<array<int, 3>> todo;

    for(int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        if (map[r][c]) {
            map[r][c] = false;
        } else {
            todo.emplace(r, c, 0); // 0 means we need to check this cell in all directions
        }
    }

    while (!todo.empty()) {
        auto [r, c, direction] = todo.front();
        todo.pop();

        if (direction == 4) continue; // All directions have been checked, move to next cell

        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};

        int nr = r + dr[direction];
        int nc = c + dc[direction];

        if (nr < 0 || nr >= H || nc < 0 || nc >= W || !map[nr][nc]) {
            ++direction;
            todo.emplace(r, c, direction);
        } else {
            map[nr][nc] = false;
            todo.emplace(nr, nc, 0);
        }
    }

    cout << (H * W - count_if(begin(map), end(map), [](const auto& row){ return count_if(begin(row), end(row), [](bool x){ return x; }); })) << endl;

    return 0;
}