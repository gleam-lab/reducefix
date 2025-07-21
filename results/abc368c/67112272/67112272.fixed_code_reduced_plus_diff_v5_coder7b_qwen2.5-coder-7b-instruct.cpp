#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<ll> h(n);
    rep(i,n)
    {
        cin >> h[i];
    }

    ll t = 0;
    while(1){
        bool flag = false;
        rep(i,n){
            if(h[i] > 0){
                t++;
                if(t % 3 == 0) h[i] -= 3;
                else h[i]--;
                flag = true;
            }
        }
        if(!flag) break;
    }

    cout << t << endl;
}