#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (long long i=0;i < (n); i++)
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    ll ans=0;
    vector<ll> h(n);
    rep(i,n)
    {
        cin >> h[i];
    }

    while(true){
        bool flag=true;
        rep(i,n){
            if(h[i]>0){
                flag=false;
                if((ans+1)%3==0) h[i]-=3;
                else h[i]--;
                ans++;
            }
        }
        if(flag) break;
    }
    cout << ans << endl;
}