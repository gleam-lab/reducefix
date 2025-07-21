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

const int INF = 1e9 + 7;

int main(){
    ll h, w, y, ans; cin >> h >> w >> y;
    ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> room[i][j];

    vector<vector<bool>> used(h, vector<bool>(w, false));

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;

    rep(i, h){
        pq.push({room[i][0], {i, 0}});
        pq.push({room[i][w - 1], {i, w - 1}});
        used[i][0] = true;
        used[i][w - 1] = true;
    }

    rep(j, w){
        pq.push({room[0][j], {0, j}});
        pq.push({room[h - 1][j], {h - 1, j}});
        used[0][j] = true;
        used[h - 1][j] = true;
    }

    ll now = 0;
    while(now < y){
        ans -= pq.size();
        while(!pq.empty()){
            auto [height, coord] = pq.top(); pq.pop();
            if(height > now) break;
            auto [i, j] = coord;
            rep(k, 4){
                ll nexi = i + dx[k], nexj = j + dy[k];
                if(0 <= nexi && nexi < h && 0 <= nexj && nexj < w && !used[nexi][nexj]){
                    pq.push({room[nexi][nexj], {nexi, nexj}});
                    used[nexi][nexj] = true;
                }
            }
        }
        cout << ans << '\n';
        now++;
    }
}