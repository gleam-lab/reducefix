#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    
    ll ans = 0;
    for (ll hi : h) {
        ll cycles = hi / 5;
        ll rem = hi % 5;
        ans += cycles * 3;
        if (rem > 0) {
            if (rem <= 2) ans += rem;
            else ans += 3;
        }
    }
    cout << ans << endl;
    return 0;
}