#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, tri = 1, ans = 0;
    cin >> n;
    vector<ll> health(n);

    for (ll i = 0; i < n; i++) {
        cin >> health[i];
    }

    ll i = 0;
    while (i < n) {
        ll h = health[i];
        if (h > 0) {
            if (tri % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
            tri++;
            ans++;
            if (h > 0) {
                health[i] = h;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    cout << ans;
}