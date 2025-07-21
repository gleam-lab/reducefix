#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

// Define data types and structures
using i64 = int64_t;
using ld = long double;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using vvv = vc<vvv<T>>;
template<typename T> using vvvv = vc<vvv<T>>;
template<typename T> using P = pair<T,T>;
using vi = vc<int>; using vvi = vc<vi>;
using Pi = pair<int, int>;

// Function to check if a cell is within the grid bounds
bool isValid(int x, int y, int H, int W) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

int main(){
    int H, W, Y; cin >> H >> W >> Y;
    vvi A(H, vi(W));
    cin >> A;

    // Priority queue to manage cells based on their elevation
    pq_c<Pi> pq;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            pq.push({A[i][j], i * W + j});
        }
    }

    // Directions for moving up, down, left, right
    vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

    // Process each year
    rep3(i, 1, Y + 1) {
        while(!pq.empty() && pq.top().first <= i) {
            auto [_, pos] = pq.top(); pq.pop();
            int x = pos / W, y = pos % W;
            A[x][y] = 0; // Mark as visited by setting elevation to 0

            // Check and mark adjacent cells
            rep(d, 4) {
                int nx = x + dx[d], ny = y + dy[d];
                if(isValid(nx, ny, H, W) && A[nx][ny] != 0) {
                    pq.push({A[nx][ny], nx * W + ny});
                    A[nx][ny] = 0; // Mark as visited
                }
            }
        }
        // Calculate remaining area
        int count = 0;
        rep(i, H) rep(j, W) if(A[i][j] != 0) ++count;
        cout << count << endl;
    }
}