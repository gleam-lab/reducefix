#include <bits/stdc++.h>
using namespace std;
struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(12);
    }
} init;

using i64 = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using Pi = pair<int, int>;

#define pb push_back
#define em emplace
#define eb emplace_back
#define el '\n'
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep3(i,l,r) for(int i = (l); i < (r); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(a) a.begin(), a.end()

int main(){
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    cin >> A;

    // Priority queue to process cells in increasing order of elevation
    priority_queue<vi, vector<vi>, greater<vi>> pq;
    vvi used(H, vi(W, 0));

    // Add all border cells to the priority queue
    rep(i, H) {
        pq.push({A[i][0], i, 0});
        used[i][0] = 1;
        if (W > 1) {
            pq.push({A[i][W-1], i, W-1});
            used[i][W-1] = 1;
        }
    }
    rep3(i, 1, W-1) {
        pq.push({A[0][i], 0, i});
        used[0][i] = 1;
        if (H > 1) {
            pq.push({A[H-1][i], H-1, i});
            used[H-1][i] = 1;
        }
    }

    int remaining = H * W;
    vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    // Process each year from 1 to Y
    rep3(year, 1, Y+1) {
        // Remove all cells with elevation <= current sea level
        while (!pq.empty() && pq.top()[0] <= year) {
            auto cell = pq.top();
            pq.pop();
            --remaining;

            // Check neighbors
            rep(d, 4) {
                int ny = cell[1] + dy[d];
                int nx = cell[2] + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (!used[ny][nx]) {
                    used[ny][nx] = 1;
                    pq.push({A[ny][nx], ny, nx});
                }
            }
        }
        cout << remaining << el;
    }
}