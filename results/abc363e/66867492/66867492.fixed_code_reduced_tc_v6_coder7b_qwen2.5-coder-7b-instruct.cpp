#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve(){
    ll h,w,y; cin >> h >> w >> y;
    vector<vector<ll>> a(h,vector<ll>(w));
    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dp(h,vector<ll>(w,INF));

    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            if(a[i][j]==0){
                dp[i][j]=0;
            }
        }
    }

    for(ll k=1;k<=y;++k){
        vector<vector<ll>> ndp(h,vector<ll>(w,INF));
        for(ll i=0;i<h;++i){
            for(ll j=0;j<w;++j){
                if(dp[i][j]!=INF){
                    ndp[i][j]=dp[i][j]+1;
                    if(i>0&&dp[i-1][j]!=INF){
                        ndp[i][j]=min(ndp[i][j],ndp[i-1][j]);
                    }
                    if(i+1<h&&dp[i+1][j]!=INF){
                        ndp[i][j]=min(ndp[i][j],ndp[i+1][j]);
                    }
                    if(j>0&&dp[i][j-1]!=INF){
                        ndp[i][j]=min(ndp[i][j],ndp[i][j-1]);
                    }
                    if(j+1<w&&dp[i][j+1]!=INF){
                        ndp[i][j]=min(ndp[i][j],ndp[i][j+1]);
                    }
                }
            }
        }
        swap(dp,ndp);
    }

    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            if(dp[i][j]==INF){
                cout << "0 ";
            }
            else{
                cout << h*w-dp[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}