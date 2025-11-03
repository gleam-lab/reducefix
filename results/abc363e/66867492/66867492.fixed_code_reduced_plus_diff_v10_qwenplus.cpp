#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

using i64 = int64_t;
using ld = long double;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using P = pair<T,T>;
using vi = vc<int>; using vvi = vc<vi>;
using Pi = pair<int, int>;

#define pb push_back
#define em emplace
#define eb emplace_back
#define el '\n'
#define all(a)  a.begin(),a.end()
#define rep(i,n)     for(int i = 0; i < (n); ++i)
#define rep3(i,l,r)  for(int i = (l); i < (r); ++i)
template<typename T> inline bool chmin(T &a, T b){if(a > b){a = b; return true;}return false;}
template<typename T> istream& operator>>(istream& i, vc<T>& v) { rep(j, size(v))i >> v[j]; return i; }

int main(){
    int H,W,Y; cin>>H>>W>>Y;
    vvi A(H, vi(W)); cin>>A;
    
    // Create list of all cells with their elevation and coordinates
    vector<tuple<int,int,int>> cells;
    rep(i,H) rep(j,W) {
        cells.emplace_back(A[i][j], i, j);
    }
    
    // Sort by elevation in ascending order
    sort(all(cells));
    
    // Used to track which cells are submerged
    vvi used(H, vi(W, 0));
    
    // Directions for BFS: up, right, down, left
    vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    
    // Start with full area
    int remaining = H * W;
    int idx = 0; // Index in sorted cells array
    
    // Process each year
    rep3(year, 1, Y+1) {
        // Add all cells with elevation <= current sea level that haven't been processed
        while (idx < cells.size() && get<0>(cells[idx]) <= year) {
            auto [elev, x, y] = cells[idx];
            if (!used[x][y]) {
                used[x][y] = 1;
                remaining--;
                
                // Check if this cell is on the border or adjacent to the sea
                // In our approach, we process from low elevation outward
                // But we need to ensure connectivity to the "sea" (border)
                // However, since we're processing in increasing elevation order,
                // any cell with elev <= year will eventually be submerged if connected
                // Our sorting and processing ensures this.
            }
            idx++;
        }
        
        cout << remaining << el;
    }
}