#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    ll T = 0;
    int idx = 0; // current enemy index

    while (idx < n) {
        T++;
        // Find the first enemy with health > 0
        while (idx < n && h[idx] <= 0) idx++;
        if (idx >= n) break;

        // Attack the frontmost alive enemy
        if (T % 3 == 0) {
            h[idx] -= 3;
        } else {
            h[idx] -= 1;
        }
    }

    cout << T << endl;
    return 0;
}