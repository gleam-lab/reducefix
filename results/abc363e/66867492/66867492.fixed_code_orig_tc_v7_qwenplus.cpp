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
template<typename T> struct cmpP { bool operator()(T l, T r){ return l.first > r.first; }};
template<typename T> using pq_cP = priority_queue<T, vc<T>, cmpP<T>>;

#define pb push_back
#define em emplace
#define eb emplace_back
#define pob pop_back
#define el '\n'
#define all(a)  a.begin(),a.end()
#define rep(i,n)     for(int i = 0; i < (n); ++i)
#define rep3(i,l,r)  for(int i = (l); i < (r); ++i)
template<typename T> inline bool chmin(T &a, T b){if(a > b){a = b; return true;}return false;}
template<typename T> istream& operator>>(istream& i, vc<T>& v) { rep(j, size(v))i >> v[j]; return i; }

int main(){
    int H,W,Y; cin>>H>>W>>Y;
    vvi A(H, vi(W)), used(H, vi(W));
    cin >> A;
    
    pq_cP<Pi> pq;
    // Mark and add all boundary cells
    rep(i, H) {
        pq.push({A[i][0], i * W + 0});
        pq.push({A[i][W-1], i * W + (W-1)});
        used[i][0] = 1;
        used[i][W-1] = 1;
    }
    rep3(i, 1, W-1) {
        pq.push({A[0][i], 0 * W + i});
        pq.push({A[H-1][i], (H-1) * W + i});
        used[0][i] = 1;
        used[H-1][i] = 1;
    }
    
    int ans = H * W;
    vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
    vi result;
    
    rep3(year, 1, Y+1) {
        while(!pq.empty() && pq.top().first <= year) {
            auto [elev, pos] = pq.top(); pq.pop();
            int r = pos / W, c = pos % W;
            
            // This cell is sinking
            --ans;
            
            // Check neighbors
            rep(d, 4) {
                int nr = r + dx[d], nc = c + dy[d];
                if(nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
                if(used[nr][nc]) continue;
                
                used[nr][nc] = 1;
                pq.push({A[nr][nc], nr * W + nc});
            }
        }
        result.pb(ans);
    }
    
    for(int x : result) cout << x << el;
}