//#define _GLIBCXX_DEBUG
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
using vi = vc<int>; using vvi = vc<vi>;
using Pi = pair<int, int>;
template<typename T> struct cmp { bool operator()(T l, T r) { return l[0] > r[0]; }};
template<typename T> using pq_c = priority_queue<T, vc<T>, cmp<T>>;

#define pb push_back
#define em emplace
#define eb emplace_back
#define el '\n'
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n)     for(int i = 0; i < (n); ++i)
#define rep3(i,l,r)  for(int i = (l); i < (r); ++i)
#define rrep(i,n)    for(int i = (n)-1; i >= 0; --i)
#define rrep3(i,l,r) for(int i = (r)-1; i >= (l); --i)
#define next_p(x) next_permutation( x )
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> istream& operator>>(istream& i, vc<T>& v) { rep(j, size(v))i >> v[j]; return i; }

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    rep(i, H) cin >> A[i];

    // visited matrix to track if a cell has already been submerged
    vvi visited(H, vi(W, 0));

    // Min-heap priority queue to simulate the spread of submerging landmasses
    using Land = array<int, 3>; // {elevation, row, col}
    auto cmpPQ = [](const Land &a, const Land &b) { return a[0] > b[0]; };
    priority_queue<Land, vector<Land>, decltype(cmpPQ)> pq(cmpPQ);

    // Initialize the boundary cells as submerged and add them to the priority queue
    rep(i, H) {
        if (!visited[i][0]) {
            visited[i][0] = 1;
            pq.push({A[i][0], i, 0});
        }
        if (!visited[i][W - 1]) {
            visited[i][W - 1] = 1;
            pq.push({A[i][W - 1], i, W - 1});
        }
    }
    rep(j, W) {
        if (!visited[0][j]) {
            visited[0][j] = 1;
            pq.push({A[0][j], 0, j});
        }
        if (!visited[H - 1][j]) {
            visited[H - 1][j] = 1;
            pq.push({A[H - 1][j], H - 1, j});
        }
    }

    int remaining = H * W;
    vi dx{0, 1, 0, -1};
    vi dy{-1, 0, 1, 0};

    vi result(Y + 1, 0); // To store area above water for each year

    int current_year = 0;
    while (current_year < Y) {
        ++current_year;
        while (!pq.empty() && pq.top()[0] <= current_year) {
            auto [elev, y, x] = pq.top();
            pq.pop();
            if (visited[y][x] == 0) continue; // Already processed
            remaining--;

            // Explore neighbors
            rep(d, 4) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny >= 0 && ny < H && nx >= 0 && nx < W && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    pq.push({A[ny][nx], ny, nx});
                }
            }
        }
        result[current_year] = remaining;
    }

    // Output results from year 1 to Y
    for (int i = 1; i <= Y; ++i) {
        cout << result[i] << el;
    }
}