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
    
    // We'll process cells in increasing order of elevation using a min-heap
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
    vector<vb> submerged(h,vb(w,false));
    
    // Add all border cells to the priority queue
    rep(i,h) {
        pq.push({room[i][0], i, 0});
        submerged[i][0] = true;
        if (w > 1) {
            pq.push({room[i][w-1], i, w-1});
            submerged[i][w-1] = true;
        }
    }
    rep(j,w) {
        if (!submerged[0][j]) {
            pq.push({room[0][j], 0, j});
            submerged[0][j] = true;
        }
        if (h > 1 && !submerged[h-1][j]) {
            pq.push({room[h-1][j], h-1, j});
            submerged[h-1][j] = true;
        }
    }
    
    ll remaining = h * w;
    vector<ll> result;
    
    // Process each year from 1 to Y
    for (ll year = 1; year <= y; year++) {
        // Remove all cells with elevation <= current sea level (year)
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            
            // This cell is now submerged
            remaining--;
            
            // Add adjacent unvisited cells to the priority queue
            rep(k,4) {
                ll ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !submerged[ni][nj]) {
                    submerged[ni][nj] = true;
                    pq.push({room[ni][nj], ni, nj});
                }
            }
        }
        result.push_back(remaining);
    }
    
    // Output results for each year
    for (ll r : result) {
        cout << r << endl;
    }
    
    return 0;
}