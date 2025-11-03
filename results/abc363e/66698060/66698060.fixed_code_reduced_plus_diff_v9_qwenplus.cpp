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
    vector room(h,vl(w));
    rep(i,h) rep(j,w) cin >> room[i][j];
    
    // Create events: when each cell gets submerged
    vector<tuple<ll,ll,ll>> events; // (elevation, i, j)
    rep(i,h) rep(j,w) {
        events.push_back({room[i][j], i, j});
    }
    sort(events.begin(), events.end());
    
    vector used(h,vb(w,0));
    ll ans = h * w;
    ll ptr = 0;
    
    // Process each year
    for(ll year = 1; year <= y; year++) {
        // Add all cells with elevation <= current sea level
        while(ptr < events.size() && get<0>(events[ptr]) <= year) {
            auto [elev, i, j] = events[ptr];
            if(!used[i][j]) {
                used[i][j] = true;
                ans--;
                
                // Check if this cell is on the border - if not, we need to ensure connectivity
                // But actually, any cell with elev <= sea level that's connected to the sea will sink
                // Our approach: we mark ALL cells with elev <= sea level as sunk
                // However, the sinking only happens if connected to the sea or already sunk area
                // So we need to use BFS from borders
            }
            ptr++;
        }
        
        cout << ans << endl;
    }
    
    // The above approach is incorrect because it doesn't account for connectivity.
    // Let's fix: use a priority queue to simulate the rising sea level
    
    // Reset
    fill(used.begin(), used.end(), vb(w, false));
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
    ans = h * w;
    
    // Initialize with all border cells
    rep(i,h) {
        pq.push({room[i][0], i, 0});
        used[i][0] = true;
        if (w > 1) {
            pq.push({room[i][w-1], i, w-1});
            used[i][w-1] = true;
        }
    }
    rep(j, w) {
        if (!used[0][j]) {
            pq.push({room[0][j], 0, j});
            used[0][j] = true;
        }
        if (h > 1 && !used[h-1][j]) {
            pq.push({room[h-1][j], h-1, j});
            used[h-1][j] = true;
        }
    }
    
    // Process year by year
    for(ll year = 1; year <= y; year++) {
        // Remove all cells that can be submerged at this sea level
        while(!pq.empty()) {
            auto [elev, i, j] = pq.top();
            if(elev > year) break;
            
            pq.pop();
            ans--; // This cell is now underwater
            
            // Check neighbors
            rep(k,4) {
                ll ni = i + dx[k], nj = j + dy[k];
                if(ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({room[ni][nj], ni, nj});
                }
            }
        }
        cout << ans << endl;
    }
}