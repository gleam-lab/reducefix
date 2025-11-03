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
    
    // Store all cells with their elevation
    vector<tuple<ll,ll,ll>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    sort(cells.begin(), cells.end());
    
    vb used(h*w, false);
    ll ans = h * w;
    
    auto idx = [&](ll i, ll j) { return i * w + j; };
    
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    
    // Add border cells to the priority queue initially
    rep(i,h) {
        pq.push({room[i][0], idx(i,0)});
        pq.push({room[i][w-1], idx(i,w-1)});
        used[idx(i,0)] = true;
        used[idx(i,w-1)] = true;
    }
    rep(j,1,w-1) {
        pq.push({room[0][j], idx(0,j)});
        pq.push({room[h-1][j], idx(h-1,j)});
        used[idx(0,j)] = true;
        used[idx(h-1,j)] = true;
    }
    
    ll cell_idx = 0;
    rep(year, y) {
        ll sea_level = year + 1;
        
        // Add all cells with elevation <= current sea level that haven't been processed
        while (cell_idx < cells.size() && get<0>(cells[cell_idx]) <= sea_level) {
            ll r = get<1>(cells[cell_idx]);
            ll c = get<2>(cells[cell_idx]);
            if (!used[idx(r,c)]) {
                pq.push({room[r][c], idx(r,c)});
                used[idx(r,c)] = true;
            }
            cell_idx++;
        }
        
        // Process all cells that will sink at this sea level
        while (!pq.empty() && pq.top().first <= sea_level) {
            auto [elev, pos] = pq.top();
            pq.pop();
            
            ll r = pos / w, c = pos % w;
            ans--;
            
            // Check neighbors
            rep(k,4) {
                ll nr = r + dx[k], nc = c + dy[k];
                if (nr >= 0 && nr < h && nc >= 0 && nc < w && !used[idx(nr,nc)]) {
                    pq.push({room[nr][nc], idx(nr,nc)});
                    used[idx(nr,nc)] = true;
                }
            }
        }
        
        cout << ans << endl;
    }
}