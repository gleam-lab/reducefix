#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define rep1(i,n) for(ll i=1;i<=(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main(){
    ll h, w, y;
    cin >> h >> w >> y;
    
    vector<vl> room(h, vl(w));
    rep(i, h) rep(j, w) cin >> room[i][j];
    
    // We'll process sinking in increasing order of elevation using a priority queue
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    vector<vb> used(h, vb(w, false));
    ll remaining = h * w;
    
    // Add all border cells to the priority queue (they are adjacent to the sea)
    rep(i, h) {
        pq.push({room[i][0], i, 0});
        used[i][0] = true;
        if (w > 1) {
            pq.push({room[i][w-1], i, w-1});
            used[i][w-1] = true;
        }
    }
    rep(j, 1, w-1) {
        pq.push({room[0][j], 0, j});
        used[0][j] = true;
        if (h > 1) {
            pq.push({room[h-1][j], h-1, j});
            used[h-1][j] = true;
        }
    }
    
    // For each year from 1 to Y, simulate the rising sea level
    rep1(year, y) {
        // Process all cells that will sink at this sea level (elevation <= year)
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            
            // This cell sinks, reduce remaining area
            remaining--;
            
            // Check neighbors and add them to PQ if not already added
            rep(k, 4) {
                ll ni = i + dx[k];
                ll nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({room[ni][nj], ni, nj});
                }
            }
        }
        
        cout << remaining << endl;
    }
    
    return 0;
}