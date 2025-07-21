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
using ld = long double;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using vvv = vc<vv<T>>;
template<typename T> using vvvv = vc<vvv<T>>;
template<typename T> using P = pair<T, T>;
using vi = vc<int>;
using vvi = vc<vi>;
using Pi = pair<int, int>;

template<typename T> struct cmp {
    bool operator()(const T &l, const T &r) { return l[0] > r[0]; }
};

int INF = 1e9 + 10;
int INF2 = 2e9 + 10;
i64 INFi64 = (i64)2e18 + 10;
int m = 998244353;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W)), visited(H, vi(W));
    cin >> A;

    priority_queue<vi, vvi, cmp<vi>> pq;
    
    // Push border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        visited[i][0] = 1;
        if (W > 1) {
            pq.push({A[i][W - 1], i, W - 1});
            visited[i][W - 1] = 1;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        pq.push({A[0][j], 0, j});
        visited[0][j] = 1;
        if (H > 1) {
            pq.push({A[H - 1][j], H - 1, j});
            visited[H - 1][j] = 1;
        }
    }

    int ans = H * W;
    vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    
    for (int year = 1; year <= Y; ++year) {
        queue<Pi> q;
        while (!pq.empty() && pq.top()[0] <= year) {
            auto cell = pq.top();
            pq.pop();
            int i = cell[1], j = cell[2];
            if (A[i][j] > year) continue; // This should not happen as per the priority queue
            --ans;
            q.emplace(i, j);
        }
        
        // BFS to propagate sinking to adjacent cells
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni < 0 || nj < 0 || ni >= H || nj >= W || visited[ni][nj]) continue;
                if (A[ni][nj] <= year) {
                    visited[ni][nj] = 1;
                    --ans;
                    q.emplace(ni, nj);
                } else {
                    visited[ni][nj] = 1;
                    pq.push({A[ni][nj], ni, nj});
                }
            }
        }
        cout << ans << '\n';
    }
}