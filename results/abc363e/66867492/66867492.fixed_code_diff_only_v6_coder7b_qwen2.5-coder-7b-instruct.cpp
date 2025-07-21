#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_Y = 100000;
const int INF = 1e9 + 10;

struct Node {
    int h, y, x;
    Node(int h, int y, int x) : h(h), y(y), x(x) {}
    bool operator<(const Node& other) const {
        return h > other.h;
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

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Node> pq;

    // Add boundary nodes to the priority queue
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        pq.emplace(A[i][W - 1], i, W - 1);
        visited[i][0] = true;
        visited[i][W - 1] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.emplace(A[0][j], 0, j);
        pq.emplace(A[H - 1][j], H - 1, j);
        visited[0][j] = true;
        visited[H - 1][j] = true;
    }

    vector<int> results(Y + 1, H * W);

    for (int t = 1; t <= Y; ++t) {
        while (!pq.empty() && pq.top().h <= t) {
            auto [h, y, x] = pq.top();
            pq.pop();
            results[t]--;
            const static int dy[] = {0, 1, 0, -1};
            const static int dx[] = {1, 0, -1, 0};
            for (int k = 0; k < 4; ++k) {
                int ny = y + dy[k], nx = x + dx[k];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx]) continue;
                visited[ny][nx] = true;
                if (A[ny][nx] <= t) {
                    pq.emplace(A[ny][nx], ny, nx);
                }
            }
        }
        cout << results[t] << endl;
    }

    return 0;
}