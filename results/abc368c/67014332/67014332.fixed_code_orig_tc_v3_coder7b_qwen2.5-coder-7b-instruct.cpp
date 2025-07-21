#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> hp(n);
    for(ll i = 0; i < n; ++i) {
        cin >> hp[i];
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(hp[i] > 0) {
            ans += (hp[i] + 2) / 3;
        }
    }

    cout << ans << "\n";

    return 0;
}