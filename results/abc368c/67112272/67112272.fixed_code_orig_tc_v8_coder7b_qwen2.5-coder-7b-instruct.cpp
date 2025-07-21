#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (long long i=0;i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    while(true) {
        bool any = false;
        rep(i, n) {
            if(h[i] > 0) {
                any = true;
                h[i]--;
                if((ans+1)%3 == 0) h[i]--;
            }
        }
        if(!any) break;
        ans++;
    }

    cout << ans << '\n';
    return 0;
}