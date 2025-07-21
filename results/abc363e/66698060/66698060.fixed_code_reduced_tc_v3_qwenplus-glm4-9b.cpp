#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); ++i)

ll H, W, Y;
vector<vector<ll>> height(H, vector<ll>(W));
vector<vector<bool>> sea(H, vector<bool>(W, false));

int main() {
    cin >> H >> W >> Y;
    for (ll i = 0; i < H; ++i) for (ll j = 0; j < W; ++j) cin >> height[i][j];
    
    // Initialize the sea and priority queue
    priority_queue<pair<ll, tuple<ll, ll>>, vector<pair<ll, tuple<ll, ll>>>, greater<pair<ll, tuple<ll, ll>>>> pq;
    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                sea[i][j] = true;
                pq.push({height[i][j], make_tuple(i, j)});
            }
        }
    }
    
    for (ll year = 1; year <= Y; ++year) {
        ll remainingArea = H * W;
        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            ll x = get<0>(pos), y = get<1>(pos);
            if (h <= year) {
                sea[x][y] = true;
                remainingArea--;
            }
            if (x > 0 && !sea[x - 1][y]) {
                if (height[x - 1][y] > year) pq.push({height[x - 1][y], make_tuple(x - 1, y)});
            }
            if (x < H - 1 && !sea[x + 1][y]) {
                if (height[x + 1][y] > year) pq.push({height[x + 1][y], make_tuple(x + 1, y)});
            }
            if (y > 0 && !sea[x][y - 1]) {
                if (height[x][y - 1] > year) pq.push({height[x][y - 1], make_tuple(x, y - 1)});
            }
            if (y < W - 1 && !sea[x][y + 1]) {
                if (height[x][y + 1] > year) pq.push({height[x][y + 1], make_tuple(x, y + 1)});
            }
        }
        cout << remainingArea << endl;
    }
}