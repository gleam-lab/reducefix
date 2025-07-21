#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

using ll = int64_t;
using ld = long double;
int inf = 1000000001;
ll INF = 1e18;

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(x) (ll)x.size()

template<typename T>bool chmin(T& a, T b){if(a > b){a = b; return true;}return false;}
template<typename T>bool chmax(T& a, T b){if(a < b){a = b; return true;}return false;}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i,H) rep(j,W) cin >> A[i][j];

    int total = H * W;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int,int>>> q(200005);

    // Initialize borders as initially flooded
    rep(i,H) rep(j,W) {
        if(i == 0 || i == H-1 || j == 0 || j == W-1) {
            visited[i][j] = true;
            q[A[i][j]].push({i, j});
        }
    }

    // Process year by year
    for (int y = 1; y <= Y; ++y) {
        while (!q[y].empty()) {
            auto [i, j] = q[y].front();
            q[y].pop();
            total--;

            rep(k,4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    int next_y = max(y, A[ni][nj]);
                    q[next_y].push({ni, nj});
                }
            }
        }
        cout << total << "\n";
    }

    return 0;
}