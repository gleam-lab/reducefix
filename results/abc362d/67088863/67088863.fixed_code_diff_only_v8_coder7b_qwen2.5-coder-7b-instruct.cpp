#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
int MOD = 1e9 + 7;
const int N = 2e5 + 5;

//const double PI = acos(-1);

ll fpow(ll a, ll b, int m = MOD){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res % m;
}

ll lcm(ll a, ll b){
    return a  / __gcd(a, b) * b;
}


void solve(){
    int n, m;
    cin >> n >> m;

    vector<ll> val(n);
    for(ll& i : val) cin >> i;
    
    vector<vector<pair<int, ll>>> adj(n);

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        a--, b--;
        adj[a].push_back({b, 1ll * w + val[a]});
        adj[b].push_back({a, 1ll * w + val[b]});
    }
    vector<ll> dist(n, INF);

    dist[0] = 0;
    vector<bool> vis(n, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [w, v] = pq.top();
        pq.pop();
        if(vis[v]) continue;
        vis[v] = 1;

        for(auto [u, ww] : adj[v]){
            if(ww + dist[v] < dist[u]){
                dist[u] = ww + dist[v];
                pq.push({dist[u], u});
            }
        }
    }

    for(int i = 1; i < n; i++) cout << dist[i] + val[i] << " ";
    cout << endl;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1;
//    cin >> t;


    while(t--){
        solve();
    }

    
    return 0;
}