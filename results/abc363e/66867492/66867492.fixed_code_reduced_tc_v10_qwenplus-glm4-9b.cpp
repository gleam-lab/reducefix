#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pair {
    int x, y, val;
    Pair(int _x, int _y, int _val) : x(_x), y(_y), val(_val) {}
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> used(H, vector<int>(W, 0));
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    int ans = H * W;

    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; i++) {
        pq.push(Pair(i, 0, A[i][0]));
        pq.push(Pair(i, W - 1, A[i][W - 1]));
        used[i][0] = used[i][W - 1] = 1;
        vis[i][0] = vis[i][W - 1] = true;
    }
    for (int j = 0; j < W; j++) {
        pq.push(Pair(0, j, A[0][j]));
        pq.push(Pair(H - 1, j, A[H - 1][j]));
        used[0][j] = used[H - 1][j] = 1;
        vis[0][j] = vis[H - 1][j] = true;
    }

    // Process each year
    for (int year = 1; year <= Y; year++) {
        ans -= pq.size(); // Subtract the number of sinking cells
        while (!pq.empty()) {
            Pair p = pq.top();
            pq.pop();

            // Check neighbors
            if (p.x > 0 && !vis[p.x - 1][p.y] && A[p.x - 1][p.y] <= year) {
                vis[p.x - 1][p.y] = true;
                pq.push(Pair(p.x - 1, p.y, A[p.x - 1][p.y]));
            }
            if (p.x < H - 1 && !vis[p.x + 1][p.y] && A[p.x + 1][p.y] <= year) {
                vis[p.x + 1][p.y] = true;
                pq.push(Pair(p.x + 1, p.y, A[p.x + 1][p.y]));
            }
            if (p.y > 0 && !vis[p.x][p.y - 1] && A[p.x][p.y - 1] <= year) {
                vis[p.x][p.y - 1] = true;
                pq.push(Pair(p.x, p.y - 1, A[p.x][p.y - 1]));
            }
            if (p.y < W - 1 && !vis[p.x][p.y + 1] && A[p.x][p.y + 1] <= year) {
                vis[p.x][p.y + 1] = true;
                pq.push(Pair(p.x, p.y + 1, A[p.x][p.y + 1]));
            }
        }
        cout << ans << endl;
    }

    return 0;
}