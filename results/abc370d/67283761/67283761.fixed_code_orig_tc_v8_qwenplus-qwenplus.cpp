#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // Grid representing if wall exists at (r, c)
    vector<vector<bool>> grid(H, vector<bool>(W, true));

    // Total number of walls
    long long remaining = 1LL * H * W;

    // For each row, keep deques for left and right directions
    vector<deque<int>> left_deque(H);   // For each row, cells from left to right
    vector<deque<int>> right_deque(H);  // From right to left
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            left_deque[r].push_back(c);
            right_deque[r].push_front(c);
        }
    }

    // For each column, keep deques for up and down directions
    vector<deque<int>> up_deque(W);
    vector<deque<int>> down_deque(W);
    for (int c = 0; c < W; ++c) {
        for (int r = 0; r < H; ++r) {
            up_deque[c].push_front(r);
            down_deque[c].push_back(r);
        }
    }

    auto get_first_wall_left = [&](int r, int c) -> int {
        while (!left_deque[r].empty() && left_deque[r].front() < c) {
            left_deque[r].pop_front();
        }
        return left_deque[r].empty() ? -1 : left_deque[r].front();
    };

    auto get_first_wall_right = [&](int r, int c) -> int {
        while (!right_deque[r].empty() && right_deque[r].front() > c) {
            right_deque[r].pop_front();
        }
        return right_deque[r].empty() ? -1 : right_deque[r].front();
    };

    auto get_first_wall_up = [&](int r, int c) -> int {
        while (!up_deque[c].empty() && up_deque[c].front() < r) {
            up_deque[c].pop_front();
        }
        return up_deque[c].empty() ? -1 : up_deque[c].front();
    };

    auto get_first_wall_down = [&](int r, int c) -> int {
        while (!down_deque[c].empty() && down_deque[c].front() > r) {
            down_deque[c].pop_front();
        }
        return down_deque[c].empty() ? -1 : down_deque[c].front();
    };

    auto remove_wall = [&](int r, int c) {
        grid[r][c] = false;
        // Remove from left/right deques
        deque<int>& lq = left_deque[r];
        deque<int>& rq = right_deque[r];
        for (auto it = lq.begin(); it != lq.end();) {
            if (*it == c) it = lq.erase(it);
            else ++it;
        }
        for (auto it = rq.begin(); it != rq.end();) {
            if (*it == c) it = rq.erase(it);
            else ++it;
        }

        // Remove from up/down deques
        deque<int>& uq = up_deque[c];
        deque<int>& dq = down_deque[c];
        for (auto it = uq.begin(); it != uq.end();) {
            if (*it == r) it = uq.erase(it);
            else ++it;
        }
        for (auto it = dq.begin(); it != dq.end();) {
            if (*it == r) it = dq.erase(it);
            else ++it;
        }

        remaining--;
    };

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        if (grid[r][c]) {
            // Wall exists, just remove it
            remove_wall(r, c);
        } else {
            // Look in four directions
            int dirs[4] = {get_first_wall_left(r, c),
                          get_first_wall_right(r, c),
                          get_first_wall_up(r, c),
                          get_first_wall_down(r, c)};
            for (int i = 0; i < 4; ++i) {
                int cr = dirs[i] / W;
                int cc = dirs[i] % W;
                if (dirs[i] != -1 && grid[cr][cc]) {
                    remove_wall(cr, cc);
                }
            }
        }
    }

    cout << remaining << endl;
}