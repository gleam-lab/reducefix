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
    
    // Store all cells with their elevation and coordinates
    vector<tuple<ll,ll,ll>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    
    // Sort by elevation in ascending order
    sort(cells.begin(), cells.end());
    
    // Union-Find or visited array to track which cells are submerged
    vector used(h, vb(w, false));
    ll remaining = h * w;
    
    // Process each year from 1 to Y
    auto it = cells.begin();
    for (ll year = 1; year <= y; year++) {
        // Submerge all cells with elevation <= current sea level (year)
        while (it != cells.end() && get<0>(*it) <= year) {
            ll i = get<1>(*it);
            ll j = get<2>(*it);
            if (!used[i][j]) {
                used[i][j] = true;
                remaining--;
            }
            it++;
        }
        cout << remaining << endl;
    }
}