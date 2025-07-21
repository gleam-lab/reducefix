#include <bits/stdc++.h>
using namespace std;

struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

using i64 = int64_t;
using ld = long double;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using vvv = vc<vv<T>>;
template<typename T> using vvvv = vc<vvv<T>>;
template<typename T> using P = pair<T,T>;
using vi = vc<int>; using vvi = vc<vi>;
using Pi = pair<int, int>;
template<typename T> struct cmp { bool operator()(T l, T r){ return l[0] > r[0]; }};
template<typename T> struct cmpP { bool operator()(T l, T r){ return l.first > r.first; }};
template<typename T> using pq_ = priority_queue<T>;
template<typename T> using pq_g = priority_queue<T, vc<T>, greater<T>>;
template<typename T> using pq_c = priority_queue<T, vc<T>, cmp<T>>;
template<typename T> using pq_cP = priority_queue<T, vc<T>, cmpP<T>>;

int main() {
    int H, W, Y; cin >> H >> W >> Y;
    vvi A(H, vi(W)), used(H, vi(W));
    cin >> A;
    pq_c<vi> pq;
    
    // Push border cells into the priority queue
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
    
    int ans = H * W;
    vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    
    for (int i = 1; i <= Y; ++i) {
        while (!pq.empty() && pq.top()[0] <= i) {
            auto a = pq.top(); pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int ny = a[1] + dy[d], nx = a[2] + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (!used[ny][nx]) {
                    used[ny][nx] = 1;
                    pq.push({A[ny][nx], ny, nx});
                }
            }
        }
        cout << ans << '\n';
    }
}