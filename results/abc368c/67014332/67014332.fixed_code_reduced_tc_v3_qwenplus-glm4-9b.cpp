#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        // Calculate how many times we can attack the enemy with multiples of 3 damage
        ans += h / 3;
        // Calculate the remaining health after attacks with 3 damage
        h %= 3;
        // For remaining health, increment the attack counter accordingly
        if (h > 0) {
            ans += 1;
        }
    }
    cout << ans;
}