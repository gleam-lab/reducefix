#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n; cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    ll t = 0;
    while(true) {
        bool done = true;
        rep(i,n) {
            if(h[i] > 0) {
                done = false;
                if((t+1)%3 == 0) h[i] -= 3;
                else h[i]--;
            }
        }
        if(done) break;
        t++;
    }

    cout << t << endl;
    return 0;
}