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
    ll idx = 0; // current enemy index

    while (idx < n) {
        T++;
        // Only attack if current frontmost enemy has health > 0
        if (h[idx] > 0) {
            if (T % 3 == 0) {
                h[idx] -= 3;
            } else {
                h[idx] -= 1;
            }
            // If this enemy's health drops to 0 or below, move to next
            if (h[idx] <= 0) {
                idx++;
            }
        } else {
            // If current enemy is already dead, move to next
            idx++;
        }
    }

    cout << T << endl;
}