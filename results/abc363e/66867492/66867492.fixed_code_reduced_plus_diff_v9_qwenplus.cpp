#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

/*--------------------------------------------------*/
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
#define debug(x) cerr << #x << "= " << x << el
#define cout_bit(a,b) cout<< bitset<b>(a) <<el;
#define cout_vc(v,e)  for(auto a1:v){ if(a1==e){ cout<<"- "; }else{ cout<<a1<<" "; } }cout<<el;
#define cout_vv(v,e)  for(auto a2:v){ cout_vc(a2,e) };
#define cout_vvv(v,e) for(auto a3:v){ cout_vv(a3,e); cout<<el; };
/*--------------------------------------------------*/
int INF    = 1e9+10;
int INF2   = 2e9+10;
i64 INFi64 = (i64)2e18+10;
int m=998244353; //m=1e9+7;
/*--------------------------------------------------*/

int main(){
    int H,W,Y; cin>>H>>W>>Y;
    vvi A(H, vi(W)), used( H, vi(W) ); cin>>A;
    pq_c<vi> pq;
    
    auto add_border = [&](int i, int j) {
        if (i >= 0 && i < H && j >= 0 && j < W && !used[i][j]) {
            used[i][j] = 1;
            pq.push({A[i][j], i, j});
        }
    };
    
    // Add all border cells
    rep(i, H) {
        add_border(i, 0);
        if (W > 1) add_border(i, W-1);
    }
    rep3(j, 1, W-1) {
        add_border(0, j);
        if (H > 1) add_border(H-1, j);
    }
    
    int ans = H * W;
    vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
    vi result;
    
    rep3(year, 1, Y+1) {
        while(!pq.empty() && pq.top()[0] <= year) {
            auto cell = pq.top(); pq.pop();
            --ans;
            
            rep(d, 4) {
                int ny = cell[1] + dy[d];
                int nx = cell[2] + dx[d];
                add_border(ny, nx);
            }
        }
        result.pb(ans);
    }
    
    for(int x : result) cout << x << el;
}