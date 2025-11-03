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
template<typename T> using pq_c = priority_queue<T, vc<T>, cmp<T>>;
/*--------------------------------------------------*/
#define pb push_back
#define em emplace
#define eb emplace_back
#define pob pop_back
#define el '\n'
#define YES cout<<"Yes"<<el
#define NO cout<<"No"<<el
#define NG cout<<-1<<el
#define ansNG(ans,ng) if(ans==ng){ NG; }else{ cout<<ans<<el; }
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n)     for(int i = 0; i < (n); ++i)
#define rep3(i,l,r)  for(int i = (l); i < (r); ++i)
#define rrep(i,n)    for(int i = (n)-1; i >= 0; --i)
#define rrep3(i,l,r) for(int i = (r)-1; i >= (l); --i)
#define next_p(x) next_permutation( x )
/*--------------------------------------------------*/
template<typename T> inline bool chmin(T &a, T b){if(a > b){a = b; return true;}return false;}
template<typename T> inline bool chmax(T &a, T b){if(a < b){a = b; return true;}return false;}
template<typename T> istream& operator>>(istream& i, vc<T>& v) { rep(j, size(v))i >> v[j]; return i; }
/*--------------------------------------------------*/
int INF    = 1e9+10;
int INF2   = 2e9+10;
i64 INFi64 = (i64)2e18+10;
int m=998244353;

int main(){
    int H,W,Y; cin>>H>>W>>Y;
    vvi A(H, vi(W)); cin>>A;
    
    // Use min-heap to process cells in order of increasing elevation
    pq_c<vi> pq;
    vvi visited(H, vi(W, 0));
    
    // Mark and add all border cells
    rep(i, H) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W-1], i, W-1});
        visited[i][0] = 1;
        visited[i][W-1] = 1;
    }
    rep3(i, 1, W-1) {
        pq.push({A[0][i], 0, i});
        pq.push({A[H-1][i], H-1, i});
        visited[0][i] = 1;
        visited[H-1][i] = 1;
    }
    
    int remaining = H * W;
    vi result;
    vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
    
    // Process each year from 1 to Y
    rep3(year, 1, Y+1) {
        // Remove all cells with elevation <= current sea level
        while (!pq.empty() && pq.top()[0] <= year) {
            auto cell = pq.top(); pq.pop();
            int h = cell[1], w = cell[2];
            
            // This cell sinks
            remaining--;
            
            // Check neighbors
            rep(d, 4) {
                int ny = h + dy[d], nx = w + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (!visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    pq.push({A[ny][nx], ny, nx});
                }
            }
        }
        result.push_back(remaining);
    }
    
    // Output results for each year
    for (int r : result) {
        cout << r << el;
    }
}