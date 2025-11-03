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
    
    // Create a list of all cells with their elevation and position
    vector<array<ll,3>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    
    // Sort by elevation in ascending order
    sort(cells.begin(), cells.end());
    
    // Union-Find or BFS from the outside? Instead: process year-by-year with priority queue
    // But better: simulate rising sea level by processing cells in order of elevation
    
    vb sunk(h*w, false);
    auto idx = [&](ll i, ll j) { return i * w + j; };
    
    ll remaining = h * w;
    ll ptr = 0;
    
    // For each year from 1 to Y
    for (ll year = 1; year <= y; year++) {
        // Sink all cells with elevation <= year that haven't been sunk yet
        while (ptr < cells.size() && cells[ptr][0] <= year) {
            ll elev = cells[ptr][0];
            ll i = cells[ptr][1];
            ll j = cells[ptr][2];
            ptr++;
            
            if (sunk[idx(i,j)]) continue;
            
            // Check if this cell is connected to the sea (i.e., on border or adjacent to already sunk cell)
            bool touchesSea = false;
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                touchesSea = true;
            } else {
                rep(k,4) {
                    ll ni = i + dx[k], nj = j + dy[k];
                    if (0 <= ni && ni < h && 0 <= nj && nj < w) {
                        if (sunk[idx(ni,nj)]) {
                            touchesSea = true;
                            break;
                        }
                    }
                }
            }
            
            if (touchesSea) {
                // Use BFS to sink all connected low-lying areas
                queue<array<ll,2>> q;
                q.push({i,j});
                sunk[idx(i,j)] = true;
                remaining--;
                
                while (!q.empty()) {
                    auto [ci, cj] = q.front(); q.pop();
                    rep(k,4) {
                        ll ni = ci + dx[k], nj = cj + dy[k];
                        if (0 <= ni && ni < h && 0 <= nj && nj < w && !sunk[idx(ni,nj)] && room[ni][nj] <= year) {
                            sunk[idx(ni,nj)] = true;
                            remaining--;
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }
        cout << remaining << endl;
    }
}