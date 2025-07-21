#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    for (ll h : H) {
        ll chunks = h / 5;
        ans += chunks * 3;
        h %= 5;
        ll t = ans;
        while (h > 0) {
            t++;
            if (t % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
        ans = t;
    }
    
    cout << ans << endl;
    return 0;
}