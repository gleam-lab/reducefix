#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

typedef int64_t i64;
typedef long double ld;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using vvv = vc<vv<T>>;
template<typename T> using vvvv = vc<vvv<T>>;
template<typename T> using P = pair<T,T>;
using vi = vc<int>; using vvi = vc<vi>;
using Pi = pair<int, int>;

const int MAXN = 1010;
int parent[MAXN * MAXN], rank[MAXN * MAXN];

void init_union_find(int n) {
    fill(parent, parent + n, -1);
    fill(rank, rank + n, 0);
}

int find(int u) {
    if (parent[u] == -1) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
}

int main() {
    int H, W, Y; cin >> H >> W >> Y;
    vv<i64> A(H, vi(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    init_union_find(H * W);

    vv<bool> visited(H, vi(W, false));

    int ans = H * W;
    for (int y = 1; y <= Y; ++y) {
        priority_queue<P<i64, Pi>, vector<P<i64, Pi>>, greater<P<i64, Pi>>> pq;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] <= y) {
                    pq.emplace(A[i][j], Pi{i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!pq.empty()) {
            auto [height, coord] = pq.top(); pq.pop();
            int i = coord.first, j = coord.second;
            if (i > 0 && A[i-1][j] <= y && !visited[i-1][j]) {
                visited[i-1][j] = true;
                unite(i * W + j, (i-1) * W + j);
            }
            if (i < H-1 && A[i+1][j] <= y && !visited[i+1][j]) {
                visited[i+1][j] = true;
                unite(i * W + j, (i+1) * W + j);
            }
            if (j > 0 && A[i][j-1] <= y && !visited[i][j-1]) {
                visited[i][j-1] = true;
                unite(i * W + j, i * W + (j-1));
            }
            if (j < W-1 && A[i][j+1] <= y && !visited[i][j+1]) {
                visited[i][j+1] = true;
                unite(i * W + j, i * W + (j+1));
            }
        }

        ans -= count_if(all(visited), [](bool x) { return x; });
        cout << ans << endl;
    }

    return 0;
}