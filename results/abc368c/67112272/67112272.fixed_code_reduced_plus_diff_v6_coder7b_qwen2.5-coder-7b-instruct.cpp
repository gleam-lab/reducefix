#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> h(n);
    rep(i,n)
    {
        cin >> h[i];
    }

    ll ans=0;
    while(true){
        bool flag=false;
        rep(i,n){
            if(h[i]>0){
                ++ans;
                if(ans%3==0){
                    h[i]-=3;
                }else{
                    --h[i];
                }
                flag=true;
            }
        }
        if(!flag) break;
    }
    cout << ans << endl;
    return 0;
}