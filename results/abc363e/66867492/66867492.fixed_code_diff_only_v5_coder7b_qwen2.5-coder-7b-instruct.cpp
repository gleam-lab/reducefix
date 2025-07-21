#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

typedef long long ll;
const int INF = 1e9 + 10;

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
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W - 1], make_pair(i, W - 1));
        visited[i][0] = true;
        visited[i][W - 1] = true;
    }
    for (int j = 1; j < W - 1; ++j) {
        pq.emplace(A[0][j], make_pair(0, j));
        pq.emplace(A[H - 1][j], make_pair(H - 1, j));
        visited[0][j] = true;
        visited[H - 1][j] = true;
    }

    int ans = H * W;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto [height, pos] = pq.top();
            pq.pop();
            --ans;

            for (int d = 0; d < 4; ++d) {
                int ny = pos.first + dy[d], nx = pos.second + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W || visited[ny][nx]) continue;
                if (A[ny][nx] <= year) {
                    visited[ny][nx] = true;
                    pq.emplace(year, make_pair(ny, nx));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}