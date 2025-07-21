#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll simulate(int i, vector<ll>& h, ll t) {
    if(h[i] <= 0) return t;
    --h[i];
    if(t % 3 == 0) {
        return simulate(i, h, t + 3);
    } else {
        return simulate(i, h, t + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; ++i) cin >> h[i];
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ans = max(ans, simulate(i, h, 0));
    }
    cout << ans << '\n';
}