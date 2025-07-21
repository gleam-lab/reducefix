#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    ll ans=0;
    vector<ll> h(n);
    rep(i,n)
    {
        cin >> h[i];
        while(h[i] > 0){
            ans++;
            if(ans % 3 == 0) h[i] -= 3;
            else h[i] -= 1;
        }
    }
    cout << ans << endl;
}