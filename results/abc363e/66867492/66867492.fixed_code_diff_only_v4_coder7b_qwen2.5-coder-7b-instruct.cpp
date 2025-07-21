#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } } init;

using i64 = int64_t;
using ld = long double;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using vvv = vc<vvv<T>>;
template<typename T> using vvvv = vc<vvv<T>>;
template<typename T> using P = pair<T, T>;
using vi = vc<int>; using vvi = vc<vi>;
using Pi = pair<int, int>;

#define pb push_back
#define em emplace
#define eb emplace_back
#define pob pop_back
#define el '\n'
#define YES cout << "Yes" << el
#define NO cout << "No" << el
#define NG cout << -1 << el
#define ansNG(ans, ng) if(ans == ng) { NG; } else { cout << ans << el; }
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep3(i, l, r) for(int i = (l); i < (r); ++i)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; --i)
#define rrep3(i, l, r) for(int i = (r) - 1; i >= (l); --i)

template<typename T> inline bool chmin(T &a, T b) { if(a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return true; } return false; }

int main() {
    int H, W, Y; cin >> H >> W >> Y;
    vvi A(H, vi(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    vvi used(H, vi(W, 0));

    queue<Pi> q;
    rep(i, H) {
        q.emplace(i, 0);
        q.emplace(i, W - 1);
        used[i][0] = 1;
        used[i][W - 1] = 1;
    }
    rep(j, W) {
        q.emplace(0, j);
        q.emplace(H - 1, j);
        used[0][j] = 1;
        used[H - 1][j] = 1;
    }

    int ans = H * W;
    vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    rep3(i, 1, Y + 1) {
        while (!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            --ans;
            rep(d, 4) {
                int ny = y + dy[d], nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (chmax(used[ny][nx], 1)) {
                    q.emplace(ny, nx);
                }
            }
        }
        cout << ans << el;
    }

    return 0;
}