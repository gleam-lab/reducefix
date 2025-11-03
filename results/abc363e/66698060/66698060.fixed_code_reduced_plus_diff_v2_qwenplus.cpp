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
    
    // Store all cells with their elevations
    vector<tuple<ll,ll,ll>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    sort(cells.begin(), cells.end());
    
    ll ans = h * w;
    vector used(h, vb(w, false));
    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> pq;
    
    // Initialize border cells
    rep(i,h){
        pq.push({room[i][0], {i, 0}});
        used[i][0] = true;
        if (w > 1) {
            pq.push({room[i][w-1], {i, w-1}});
            used[i][w-1] = true;
        }
    }
    rep(j, w) {
        if (h > 1) {
            pq.push({room[0][j], {0, j}});
            used[0][j] = true;
            if (h > 1 && j > 0 && j < w-1) {
                pq.push({room[h-1][j], {h-1, j}});
                used[h-1][j] = true;
            }
        }
    }
    
    ll idx = 0;
    vector<ll> result;
    
    for (ll year = 1; year <= y; year++) {
        // Process all cells that sink at this sea level
        while (!pq.empty() && pq.top().first <= year) {
            auto [elev, pos] = pq.top();
            pq.pop();
            ll i = pos.first, j = pos.second;
            
            if (!used[i][j]) continue; // Already processed
            
            ans--;
            used[i][j] = false; // Mark as sunk
            
            // Add adjacent cells that haven't been added to queue yet
            rep(k,4){
                ll ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && used[ni][nj]) {
                    pq.push({room[ni][nj], {ni, nj}});
                    used[ni][nj] = false; // Prevent duplicate additions
                }
            }
        }
        
        // Add cells from the sorted list that are now reachable and not yet in the system
        while (idx < cells.size()) {
            auto [elev, i, j] = cells[idx];
            if (elev > year) break;
            
            // Only add interior cells that haven't been processed
            if ((i > 0 && i < h-1 && j > 0 && j < w-1) && 
                (used[i][j] || (used[i][j] == false && find_if(pq.begin(), pq.end(), 
                    [&](const auto& p){ return p.second.first == i && p.second.second == j; }) == pq.end()))) {
                pq.push({elev, {i, j}});
                used[i][j] = true;
            }
            idx++;
        }
        
        result.push_back(ans);
    }
    
    // Output results
    for (ll res : result) {
        cout << res << endl;
    }
}