#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repi(i,n) for(int i=1;i<=(int)n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define repj(j,n) for(int j=0;j<(int)n;j++)
#define repkj(j,n) for(int j=1;j<=(int)n;j++)
#define repdkj(j,n) for(int j=n-1;j>=0;j--)
#define rep2(i,a,b) for(int i=a;i<(int)b;i++)
#define rep2j(j,a,b) for(int j=a;j<(int)b;j++)
#define rep2d(i,a,b) for(int i=b-1;i>=a;i--)
#define rep2dj(j,a,b) for(int j=b-1;j>=a;j--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define nl '\n'
#define sp ' '
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define yes "YES"
#define no "NO"

const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const double EPS = 1e-9;

template<typename T>
using minpq = priority_queue<T,vector<T>,greater<T>>;
template<typename T>
using maxpq = priority_queue<T>;

void solve() {
    ll h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<ll>> grid(h, vector<ll>(w, 1));
    
    while(q--) {
        ll r, c;
        cin >> r >> c;
        r--, c--;
        
        if(grid[r][c] == 0) continue;
        
        grid[r][c] = 0;
        
        // Check up
        for(ll i = r - 1; i >= 0; i--) {
            if(grid[i][c]) break;
            grid[i][c] = 0;
        }
        
        // Check down
        for(ll i = r + 1; i < h; i++) {
            if(grid[i][c]) break;
            grid[i][c] = 0;
        }
        
        // Check left
        for(ll j = c - 1; j >= 0; j--) {
            if(grid[r][j]) break;
            grid[r][j] = 0;
        }
        
        // Check right
        for(ll j = c + 1; j < w; j++) {
            if(grid[r][j]) break;
            grid[r][j] = 0;
        }
    }
    
    ll ans = 0;
    for(auto &row : grid) {
        for(auto &cell : row) {
            ans += cell;
        }
    }
    
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}