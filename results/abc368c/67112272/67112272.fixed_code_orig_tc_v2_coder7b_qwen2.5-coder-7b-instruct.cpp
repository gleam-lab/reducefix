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
    while(true){
        bool all_zero = true;
        for(int i = 0; i < n; i++){
            if(h[i] > 0){
                all_zero = false;
                if((t+1)%3 == 0){
                    h[i] -= 3;
                }else{
                    h[i]--;
                }
            }
        }
        if(all_zero){
            break;
        }
        t++;
    }
    
    cout << t << endl;
    return 0;
}