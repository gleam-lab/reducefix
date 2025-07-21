#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repj(j,n) for(int j=0;j<n;j++)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define mset(x,a) memset(x,a,sizeof(x))

const int mxN = 4e5 + 5;
const ll INF = LLONG_MAX / 2;
const int MOD = 1e9 + 7;

vvi adj(mxN);
int n,m,q;
vi par(mxN);

void init(int n) {
    for(int i=1; i<=n; ++i) {
        par[i] = i;
    }
}

int find(int u) {
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) par[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> q;
    init(n*m);
    vi walls(n*m, 1);
    vvi vis(n*m, vi(m, 0));
    
    auto get_idx = [&](int x, int y) -> int { return (x-1)*m + y; };
    
    while(q--) {
        int x,y; cin >> x >> y;
        --x; --y;
        int idx = get_idx(x,y);
        
        if(vis[idx]) continue;
        
        vis[idx] = 1;
        walls[idx] = 0;
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        for(int i=0; i<4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[get_idx(nx,ny)] && walls[get_idx(nx,ny)]) {
                merge(idx, get_idx(nx,ny));
            }
        }
    }
    
    unordered_set<int> s;
    for(int i=0; i<n*m; ++i) {
        if(walls[i]) s.insert(find(i));
    }
    
    cout << sz(s) << '\n';
    
    return 0;
}