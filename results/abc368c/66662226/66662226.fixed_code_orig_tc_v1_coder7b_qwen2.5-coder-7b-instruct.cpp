#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    ll ans = 0;
    for (ll &x : a) {
        while (x > 0) {
            ans++;
            if (ans % 3 == 0) x -= 3;
            else x--;
        }
    }
    
    cout << ans << endl;
}