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
    // We'll simulate from sea level 1 to y
    ll total = h * w;
    vector<vb> submerged(h, vb(w, false));
    priority_queue<vl, vector<vl>, greater<vl>> pq;
    
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
    
    ll ans = total;
    ll year = 1;
    
    while (year <= y) {
        // Process all cells that get submerged at current sea level or below
        while (!pq.empty() && pq.top()[0] <= year) {
            ll elevation = pq.top()[0];
            ll i = pq.top()[1];
            ll j = pq.top()[2];
            pq.pop();
            
            // This cell is now underwater
            // Check its neighbors
            rep(k,4) {
                ll ni = i + dx[k];
                ll nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !submerged[ni][nj]) {
                    submerged[ni][nj] = true;
                    pq.push({room[ni][nj], ni, nj});
                }
            }
            ans--;
        }
        cout << ans << endl;
        year++;
    }
}