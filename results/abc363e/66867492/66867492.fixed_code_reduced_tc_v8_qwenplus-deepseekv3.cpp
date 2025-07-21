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
    bool operator()(const T& l, const T& r) { return l > r; }
};
template<typename T> using pq_g = priority_queue<T, vc<T>, greater<T>>;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vvi used(H, vi(W, 0));
    pq_g<pair<int, Pi>> pq;

    // Push all border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        if (!used[i][0]) {
            pq.push({A[i][0], {i, 0}});
            used[i][0] = 1;
        }
        if (!used[i][W-1]) {
            pq.push({A[i][W-1], {i, W-1}});
            used[i][W-1] = 1;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (!used[0][j]) {
            pq.push({A[0][j], {0, j}});
            used[0][j] = 1;
        }
        if (!used[H-1][j]) {
            pq.push({A[H-1][j], {H-1, j}});
            used[H-1][j] = 1;
        }
    }

    int ans = H * W;
    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto current = pq.top();
            pq.pop();
            int y = current.second.first;
            int x = current.second.second;
            --ans;
            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny >= 0 && ny < H && nx >= 0 && nx < W && !used[ny][nx]) {
                    used[ny][nx] = 1;
                    pq.push({A[ny][nx], {ny, nx}});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}