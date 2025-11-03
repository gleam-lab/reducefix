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
    
    // Create list of all cells with their elevation and position
    vector<tuple<ll,ll,ll>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    
    // Sort by elevation in ascending order
    sort(cells.begin(), cells.end());
    
    // Union-Find or BFS from the edges? Instead: process rising sea level
    // We'll simulate year-by-year but efficiently using sorted events
    vb sunk(h*w, false);
    auto idx = [&](ll i, ll j) { return i * w + j; };
    
    ll remaining = h * w;
    ll ptr = 0; // pointer to next cell in sorted list
    
    // Process each year
    for (ll year = 1; year <= y; year++) {
        // Add all cells with elevation <= current sea level that haven't been processed
        while (ptr < cells.size() && get<0>(cells[ptr]) <= year) {
            ll i = get<1>(cells[ptr]);
            ll j = get<2>(cells[ptr]);
            if (!sunk[idx(i,j)]) {
                // This cell is now submerged
                sunk[idx(i,j)] = true;
                remaining--;
            }
            ptr++;
        }
        
        cout << remaining << endl;
    }
}