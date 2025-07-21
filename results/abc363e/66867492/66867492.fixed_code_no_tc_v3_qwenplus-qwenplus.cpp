//#define _GLIBCXX_DEBUG
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
template<typename T> using pq_ = priority_queue<T>;
template<typename T> using pq_g = priority_queue<T, vc<T>, greater<T>>;
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
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // visited array to mark cells that have been submerged
    vvi visited(H, vi(W, 0));

    // Min-heap priority queue to process cells in increasing order of elevation
    using Cell = tuple<int, int, int>; // (elevation, row, col)
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    // Initialize the queue with border cells
    for (int i = 0; i < H; ++i) {
        for (int j : {0, W - 1}) {
            if (!visited[i][j]) {
                visited[i][j] = 1;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    for (int j = 1; j < W - 1; ++j) {
        for (int i : {0, H - 1}) {
            if (!visited[i][j]) {
                visited[i][j] = 1;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    int remaining = H * W;
    vi results(Y + 2); // Store results to avoid printing during processing

    // Process the priority queue
    while (!pq.empty()) {
        auto [elev, i, j] = pq.top();
        pq.pop();

        // This cell is now submerged
        remaining--;

        // For each year up to elev, assign the current remaining area
        for (int y = max(1, elev); y <= min(Y, elev); ++y) {
            if (results[y] == 0) results[y] = remaining;
        }

        // Flood fill neighbors
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int dir = 0; dir < 4; ++dir) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                visited[ni][nj] = 1;
                pq.emplace(A[ni][nj], ni, nj);
            }
        }
    }

    // Fill in any years where no new cells were submerged that year
    for (int i = 1; i <= Y; ++i) {
        if (results[i] == 0) {
            results[i] = remaining;
        }
        cout << results[i] << el;
    }
}