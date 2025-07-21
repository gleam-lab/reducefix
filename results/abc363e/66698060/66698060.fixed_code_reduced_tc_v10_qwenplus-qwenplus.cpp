#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<ll>> A(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }

    // We'll use a max-heap to process cells in decreasing order of elevation
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Enqueue all boundary cells
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.emplace(A[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    ll remaining = h * w;
    vector<ll> ans(y + 2);  // To store answers for years 1..Y
    ans[y] = remaining;  // Initially whole island is above sea level

    while (!pq.empty()) {
        auto [elev, x, y_pos] = pq.top();
        pq.pop();

        // This means this update happens at sea level = elev
        remaining--;
        ans[elev] = remaining;

        for (ll d = 0; d < 4; ++d) {
            ll nx = x + dx[d];
            ll ny = y_pos + dy[d];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // Fill in missing values using previous ones
    for (ll i = y; i > 0; --i) {
        if (ans[i] > ans[i + 1]) {
            ans[i] = ans[i + 1];
        } else {
            ans[i] = ans[i];
        }
    }

    for (ll i = 1; i <= y; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}