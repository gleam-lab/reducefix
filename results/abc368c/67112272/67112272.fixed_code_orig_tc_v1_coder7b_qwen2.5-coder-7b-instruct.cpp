#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (long long i=0;i < (n); i++)
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll ans=0;
    vector<ll> h(n);
    rep(i,n){
        cin >> h[i];
    }

    while(true){
        bool flag=true;
        rep(i,n){
            if(h[i]>0){
                flag=false;
                break;
            }
        }
        if(flag) break;

        ans++;
        for(int i=0;i<n;i++){
            if(h[i]>0){
                if(ans%3==0){
                    h[i]-=3;
                }else{
                    h[i]--;
                }
            }
        }
    }
    cout << ans << endl;
}