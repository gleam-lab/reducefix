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
template<typename T> using pq_c = priority_queue<T, vector<T>, greater<T>>;

int main(){
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Mark border cells as initially submerged or at risk
    vvi used(H, vi(W, 0));
    priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
    
    // Add all border cells to the priority queue
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        used[i][0] = 1;
        if (W > 1) {
            pq.push({A[i][W-1], i, W-1});
            used[i][W-1] = 1;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        pq.push({A[0][j], 0, j});
        used[0][j] = 1;
        if (H > 1) {
            pq.push({A[H-1][j], H-1, j});
            used[H-1][j] = 1;
        }
    }

    int remaining = H * W;
    vi result;
    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};

    // Process each year from 1 to Y
    for (int year = 1; year <= Y; ++year) {
        // Remove all cells that sink at this sea level (elevation <= year)
        while (!pq.empty() && pq.top()[0] <= year) {
            auto [elev, x, y] = pq.top();
            pq.pop();
            --remaining;

            // Check neighbors
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !used[nx][ny]) {
                    used[nx][ny] = 1;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
        cout << remaining << '\n';
    }
}