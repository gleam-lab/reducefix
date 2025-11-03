#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int main(){
    ll h,w,y;cin >> h >> w >> y;
    vector<vl> room(h,vl(w));
    rep(i,h) rep(j,w) cin >> room[i][j];
    
    // Create events: when each cell gets submerged
    vector<tuple<ll,ll,ll>> cells; // (elevation, i, j)
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    sort(cells.begin(), cells.end());
    
    vb used(h*w, 0);
    auto idx = [&](ll i, ll j) { return i * w + j; };
    
    ll remaining = h * w;
    ll ptr = 0;
    
    // Process each year
    for(ll year = 1; year <= y; year++) {
        // Add all cells that get submerged at this sea level
        while(ptr < cells.size() && get<0>(cells[ptr]) <= year) {
            ll i = get<1>(cells[ptr]);
            ll j = get<2>(cells[ptr]);
            ll id = idx(i, j);
            
            if(!used[id]) {
                used[id] = true;
                remaining--;
                
                // Check if this cell is on the border or adjacent to already submerged cell
                // Actually, with our approach, we need to use BFS from borders
                // Let's change strategy: simulate from borders using priority queue
            }
            ptr++;
        }
        
        cout << remaining << endl;
    }
}

// The above approach is still flawed. Let's implement the correct solution:

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<ll>> A(h, vector<ll>(w));
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> A[i][j];
        }
    }
    
    // We'll use a different approach: process cells in order of elevation
    // Starting from the lowest elevation cells on the border, flood inward
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    // Add all border cells to the priority queue
    for (ll i = 0; i < h; i++) {
        pq.push({A[i][0], i, 0});
        visited[i][0] = true;
        
        if (w > 1) {
            pq.push({A[i][w-1], i, w-1});
            visited[i][w-1] = true;
        }
    }
    
    for (ll j = 1; j < w-1; j++) {
        pq.push({A[0][j], 0, j});
        visited[0][j] = true;
        
        if (h > 1) {
            pq.push({A[h-1][j], h-1, j});
            visited[h-1][j] = true;
        }
    }
    
    ll remaining = h * w;
    vector<ll> result;
    
    // Process cells in order of increasing elevation
    while (!pq.empty()) {
        auto [elev, i, j] = pq.top();
        pq.pop();
        
        // This cell gets submerged at time = elev
        if (elev <= y) {
            result.push_back(elev);
        }
        
        // Explore neighbors
        int di[] = {0, 1, 0, -1};
        int dj[] = {1, 0, -1, 0};
        
        for (ll d = 0; d < 4; d++) {
            ll ni = i + di[d];
            ll nj = j + dj[d];
            
            if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj]) {
                visited[ni][nj] = true;
                pq.push({A[ni][nj], ni, nj});
            }
        }
    }
    
    // Now process the years
    sort(result.begin(), result.end());
    ll idx = 0;
    ll current = h * w;
    
    for (ll year = 1; year <= y; year++) {
        while (idx < result.size() && result[idx] <= year) {
            current--;
            idx++;
        }
        cout << current << '\n';
    }
    
    return 0;
}