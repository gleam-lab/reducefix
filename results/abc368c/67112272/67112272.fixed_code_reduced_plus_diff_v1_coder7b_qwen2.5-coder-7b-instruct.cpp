#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<ll> h(n);
    rep(i,n)
    {
        cin >> h[i];
    }

    ll ans = 0;
    while(true){
        bool flag = false;
        rep(i,n){
            if(h[i] > 0){
                flag = true;
                if((ans+1)%3 == 0){
                    h[i] -= 3;
                }else{
                    h[i]--;
                }
            }
        }
        
        if(!flag) break;
        ans++;
    }

    cout << ans << endl;
    return 0;
}