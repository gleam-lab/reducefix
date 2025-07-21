#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for(ll &x : h) cin >> x;
    
    ll ans = 0, t = 0;
    while(true) {
        bool changed = false;
        for(ll &x : h) {
            if(x > 0) {
                changed = true;
                t++;
                if(t % 3 == 0) x -= 3;
                else x -= 1;
            }
        }
        if(!changed) break;
        ans += t;
    }
    cout << ans << endl;
    return 0;
}