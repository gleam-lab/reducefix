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
    
    // Create a list of all cells with their elevations
    vector<tuple<ll,ll,ll>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    // Sort by elevation in ascending order
    sort(cells.begin(), cells.end());
    
    vb used(h*w, false);
    auto get_idx = [&](ll i, ll j) { return i * w + j; };
    
    ll remaining = h * w;
    ll ptr = 0;
    
    // Process each year from 1 to y
    for (ll year = 1; year <= y; year++) {
        // Add all cells with elevation <= current sea level
        while (ptr < cells.size() && get<0>(cells[ptr]) <= year) {
            ll i = get<1>(cells[ptr]);
            ll j = get<2>(cells[ptr]);
            ll idx = get_idx(i, j);
            
            if (!used[idx]) {
                used[idx] = true;
                remaining--;
                
                // Check if this cell is on the border - if so, start flood fill
                bool is_border = (i == 0 || i == h-1 || j == 0 || j == w-1);
                if (is_border) {
                    // Use BFS to flood from border cells that are submerged
                    queue<pair<ll,ll>> q;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto [ci, cj] = q.front(); q.pop();
                        
                        rep(k,4) {
                            ll ni = ci + dx[k], nj = cj + dy[k];
                            if (0 <= ni && ni < h && 0 <= nj && nj < w) {
                                ll nidx = get_idx(ni, nj);
                                if (!used[nidx] && room[ni][nj] <= year) {
                                    used[nidx] = true;
                                    remaining--;
                                    q.push({ni, nj});
                                }
                            }
                        }
                    }
                }
            }
            ptr++;
        }
        
        // After processing all cells with elevation <= year, output remaining area
        cout << remaining << endl;
    }
}