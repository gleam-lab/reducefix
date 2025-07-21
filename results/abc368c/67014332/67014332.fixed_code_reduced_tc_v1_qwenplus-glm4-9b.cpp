#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        sum += h; // Sum up all the health points of enemies
    }
    // For each multiple of 3, we can attack an enemy 3 times, reducing its health by 3
    // For the remaining health points, we need to attack once per health point
    ll ans = (sum / 3) * 3 + (sum % 3); // (sum / 3) * 3 is the number of attacks for multiples of 3
    cout << ans;
    return 0;
}