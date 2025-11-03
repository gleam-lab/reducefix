#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

using i64 = int64_t;
using ld = long double;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using vvi = vc<vc<T>>;
template<typename T> using vi = vc<T>;
template<typename T> using P = pair<T,T>;
using Pi = pair<int, int>;

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
template<typename T> inline bool chmin(T &a, T b){if(a > b){a = b; return true;}return false;}
template<typename T> inline bool chmax(T &a, T b){if(a < b){a = b; return true;}return false;}
template<typename T> istream& operator>>(istream& i, vc<T>& v) { rep(j, size(v))i >> v[j]; return i; }

int main(){
    int H,W,Y; 
    cin>>H>>W>>Y;
    vvi A(H, vi(W)); 
    cin>>A;
    
    // Priority queue to process cells in order of elevation
    priority_queue<Pi, vi<Pi>, greater<Pi>> pq;
    vvi used(H, vi(W, 0));
    int total = H * W;
    
    // Add all border cells to the priority queue
    rep(i, H) {
        pq.push({A[i][0], i * W + 0});
        pq.push({A[i][W-1], i * W + (W-1)});
        used[i][0] = 1;
        used[i][W-1] = 1;
    }
    rep3(j, 1, W-1) {
        pq.push({A[0][j], 0 * W + j});
        pq.push({A[H-1][j], (H-1) * W + j});
        used[0][j] = 1;
        used[H-1][j] = 1;
    }
    
    int remaining = total;
    vi result(Y+1);
    vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
    
    rep3(year, 1, Y+1) {
        // Process all cells with elevation <= current sea level
        while (!pq.empty() && pq.top().first <= year) {
            auto [elevation, pos] = pq.top();
            pq.pop();
            
            int r = pos / W, c = pos % W;
            // This cell is submerged
            remaining--;
            
            // Check neighbors
            rep(d, 4) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
                if (!used[nr][nc]) {
                    used[nr][nc] = 1;
                    pq.push({A[nr][nc], nr * W + nc});
                }
            }
        }
        result[year] = remaining;
    }
    
    rep3(i, 1, Y+1) {
        cout << result[i] << el;
    }
}