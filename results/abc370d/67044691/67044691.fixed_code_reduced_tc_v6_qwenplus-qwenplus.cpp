#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,r) for(ll i=0;i<(ll)r;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
    ll h,w,q;cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    
    // Initialize all cells to have walls
    rep(i,h) rep(j,w){
        row[i].insert(j);
        col[j].insert(i);
    }

    rep(_, q){
        ll r, c; cin >> r >> c;
        r--; c--;

        if(row[r].find(c) == row[r].end()){
            // No wall at (r,c), destroy the first walls in each direction
            vector<pair<ll,ll>> to_remove;

            // Right
            auto rit = row[r].upper_bound(c);
            if(rit != row[r].end()) to_remove.push_back({r, *rit});

            // Left
            auto lit = row[r].lower_bound(c);
            if(lit != row[r].begin()) {
                lit--;
                to_remove.push_back({r, *lit});
            }

            // Down
            auto dit = col[c].upper_bound(r);
            if(dit != col[c].end()) to_remove.push_back({*dit, c});

            // Up
            auto uit = col[c].lower_bound(r);
            if(uit != col[c].begin()) {
                uit--;
                to_remove.push_back({*uit, c});
            }

            // Remove the walls found in each direction
            for(auto [x, y] : to_remove){
                row[x].erase(y);
                col[y].erase(x);
            }
        } else {
            // Wall exists at (r,c), remove it
            row[r].erase(c);
            col[c].erase(r);
        }
    }

    ll ans = 0;
    rep(i,h) ans += row[i].size();
    cout << ans << endl;
}