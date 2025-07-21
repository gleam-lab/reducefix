#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n; cin >> n;
    ll ans = 0;
    vector<ll> h(n);
    
    rep(i, n) {
        cin >> h[i];
    }

    // Traverse from the front to the back of the enemies
    for (ll i = 0; i < n; ++i) {
        // If the current enemy's health is greater than 0
        while (h[i] > 0) {
            // If the current attack count (ans) is a multiple of 3, we can attack with 3 damage
            if (ans % 3 == 0) {
                h[i] -= 3;
                // If the enemy still has health left, we need another attack
                if (h[i] > 0) {
                    ans++;
                }
            } else {
                // Otherwise, we attack with 1 damage
                h[i]--;
                ans++;
                // If after the attack, the enemy's health is still greater than 0, we can attack with 3 damage
                if (h[i] > 0) {
                    ans += 2;
                }
            }
        }
    }

    cout << ans << endl;
}