#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll ans=0;
    vector<ll> h(n);
    rep(i,n)
    {
        cin >> h[i];
    }

    while(true){
        bool all_zero=true;
        rep(i,n){
            if(h[i]>0){
                all_zero=false;
                break;
            }
        }
        if(all_zero) break;

        ll t=0;
        while(t<n && h[t]<=0){
            t++;
        }
        if(t==n) break;

        ll cnt=0;
        while(cnt<h[t]){
            cnt++;
            if((t+cnt)%3==0) h[t]-=3;
            else h[t]--;
        }
        h[t]-=cnt;
        ans+=(t+cnt);
    }

    cout << ans << endl;
}