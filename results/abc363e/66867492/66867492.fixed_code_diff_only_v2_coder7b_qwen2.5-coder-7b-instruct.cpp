#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

/*--------------------------------------------------*/
using i64 = int64_t;
using ld = long double;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using vvv = vc<vvv<T>>;
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
#define cout_vv(v,e)  for(auto a2:v){ cout_vc(a2,e) };cout<<el;
#define cout_vvv(v,e) for(auto a3:v){ cout_vv(a3,e); cout<<el; };
/*--------------------------------------------------*/
int INF    = 1e9+10;
int INF2   = 2e9+10;
i64 INFi64 = (i64)2e18+10;
int m=998244353; //m=1e9+7;
/*--------------------------------------------------*/

int main(){
    int H,W,Y; cin>>H>>W>>Y;
    vvi A(H, vi(W)); cin>>A;
    pq_c<P<int, Pi>> pq;
    rep( i, H ){
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W-1], make_pair(i, W-1));
        A[i][0] = INF;
        A[i][W-1] = INF;
    }
    rep3( i, 1, W-1 ){
        pq.emplace(A[0][i], make_pair(0, i));
        pq.emplace(A[H-1][i], make_pair(H-1, i));
        A[0][i] = INF;
        A[H-1][i] = INF;
    }
    int ans = H * W - 2 * (H + W - 2);
    vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
    rep3( i, 1, Y+1 ){
        while( !pq.empty() && pq.top().first <= i ){
            auto [h, p] = pq.top(); pq.pop();
            --ans;
            rep( d, 4 ){
                int ny = p.first + dy[d], nx = p.second + dx[d];
                if( ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if( A[ny][nx] != INF ){
                    A[ny][nx] = INF;
                    pq.emplace(h, make_pair(ny, nx));
                }
            }
        }
        cout<<ans<<el;
    }
}