#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<ll>> A(H, vector<ll>(W));
    for (ll i = 0; i < H; ++i)
        for (ll j = 0; j < W; ++j)
            cin >> A[i][j];

    // Priority Queue stores {elevation, row, col}
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Initialize the border cells
    for (ll i = 0; i < H; ++i) {
        if (!vis[i][0]) {
            pq.push({A[i][0], i, 0});
            vis[i][0] = true;
        }
        if (!vis[i][W - 1]) {
            pq.push({A[i][W - 1], i, W - 1});
            vis[i][W - 1] = true;
        }
    }

    for (ll j = 1; j < W - 1; ++j) {
        if (!vis[0][j]) {
            pq.push({A[0][j], 0, j});
            vis[0][j] = true;
        }
        if (!vis[H - 1][j]) {
            pq.push({A[H - 1][j], H - 1, j});
            vis[H - 1][j] = true;
        }
    }

    ll remaining = H * W;
    ll year = 1;

    while (year <= Y && !pq.empty()) {
        while (!pq.empty() && pq.top()[0] <= year) {
            auto top = pq.top(); pq.pop();
            remaining--;

            ll x = top[1];
            ll y = top[2];

            for (ll d = 0; d < 4; ++d) {
                ll nx = x + dx[d];
                ll ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
        cout << remaining << "\n";
        year++;
    }

    // If we finish processing before Y years, fill the rest with the same value
    while (year <= Y) {
        cout << remaining << "\n";
        year++;
    }

    return 0;
}