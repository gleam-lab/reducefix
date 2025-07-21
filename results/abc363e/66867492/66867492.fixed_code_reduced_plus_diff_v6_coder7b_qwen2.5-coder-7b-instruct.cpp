#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct State {
    int h, w, height;
    State(int h, int w, int height) : h(h), w(w), height(height) {}
    bool operator<(const State& other) const {
        return height > other.height;
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<State> pq;
    vector<vector<bool>> used(H, vector<bool>(W, false));

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        pq.emplace(i, 0, A[i][0]);
        pq.emplace(i, W - 1, A[i][W - 1]);
        used[i][0] = true;
        used[i][W - 1] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.emplace(0, j, A[0][j]);
        pq.emplace(H - 1, j, A[H - 1][j]);
        used[0][j] = true;
        used[H - 1][j] = true;
    }

    while (!pq.empty()) {
        auto [h, w, height] = pq.top();
        pq.pop();

        for (int k = 0; k < 4; ++k) {
            int nh = h + dx[k], nw = w + dy[k];
            if (nh >= 0 && nh < H && nw >= 0 && nw < W && !used[nh][nw]) {
                used[nh][nw] = true;
                pq.emplace(nh, nw, A[nh][nw]);
            }
        }
    }

    vector<int> areas(Y);
    for (int i = 0; i < Y; ++i) {
        int curr_level = i + 1;
        int count = 0;

        priority_queue<State> pq;
        for (int j = 0; j < H; ++j) {
            pq.emplace(j, 0, A[j][0]);
            pq.emplace(j, W - 1, A[j][W - 1]);
            used[j][0] = false;
            used[j][W - 1] = false;
        }
        for (int j = 0; j < W; ++j) {
            pq.emplace(0, j, A[0][j]);
            pq.emplace(H - 1, j, A[H - 1][j]);
            used[0][j] = false;
            used[H - 1][j] = false;
        }

        while (!pq.empty()) {
            auto [h, w, height] = pq.top();
            pq.pop();

            if (height <= curr_level) {
                count++;
                for (int k = 0; k < 4; ++k) {
                    int nh = h + dx[k], nw = w + dy[k];
                    if (nh >= 0 && nh < H && nw >= 0 && nw < W && !used[nh][nw]) {
                        used[nh][nw] = true;
                        pq.emplace(nh, nw, A[nh][nw]);
                    }
                }
            }
        }

        areas[i] = count;
    }

    for (int i = 0; i < Y; ++i) {
        cout << areas[i] << endl;
    }

    return 0;
}