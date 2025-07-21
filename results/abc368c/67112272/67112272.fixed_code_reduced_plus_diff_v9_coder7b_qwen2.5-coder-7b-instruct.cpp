#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
typedef long long ll;
const ll INF = LLONG_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    ll ans = 0, t = 0;
    while(true) {
        bool changed = false;
        rep(i,n) {
            if(h[i] > 0) {
                if(t % 3 == 0) h[i] -= 3;
                else h[i]--;
                t++;
                changed = true;
            }
        }
        if(!changed) break;
    }

    cout << t << endl;
    return 0;
}