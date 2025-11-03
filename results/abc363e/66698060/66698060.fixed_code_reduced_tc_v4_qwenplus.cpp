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
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
    vector<vb> used(h,vb(w,false));
    ll remaining = h * w;
    
    // Add all border cells to the priority queue
    rep(i,h){
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
    
    // Process years in order
    for (ll year = 1; year <= y; year++) {
        // Remove all cells that submerge at this sea level
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            remaining--;
            
            // Check neighbors
            rep(k,4){
                ll ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({room[ni][nj], ni, nj});
                }
            }
        }
        cout << remaining << endl;
    }
}