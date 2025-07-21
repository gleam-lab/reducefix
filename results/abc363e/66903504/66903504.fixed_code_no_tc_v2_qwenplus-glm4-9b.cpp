#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxH = 1000;
const int maxW = 1000;
const int maxY = 100000;
const int MAX_ELEVATION = 100000;

ll H, W, Y;
int A[maxH][maxW];
ll ans = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(ll year) {
    vector<pair<ll, ll>> queue;
    vector<vector<bool>> visited(maxH, vector<bool>(maxW, false));

    // Enqueue all edges and set visited
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            if (A[i][j] <= year) {
                queue.emplace_back(i, j);
                visited[i][j] = true;
                ans++;
            }
        }
    }

    // Perform BFS
    while (!queue.empty()) {
        auto [y, x] = queue.front();
        queue.pop();

        for (int d = 0; d < 4; d++) {
            ll ny = y + dy[d];
            ll nx = x + dx[d];

            // Check if the adjacent cell is within the bounds and not visited
            if (ny >= 0 && ny < H && nx >= 0 && nx < W && !visited[ny][nx]) {
                if (A[ny][nx] <= year) {
                    visited[ny][nx] = true;
                    ans--;
                    queue.emplace_back(ny, nx);
                }
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;

    // Input the island elevation
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Calculate the area of the island above the sea level for each year
    for (ll year = 1; year <= Y; year++) {
        bfs(year);
        cout << ans << endl;
    }

    return 0;
}