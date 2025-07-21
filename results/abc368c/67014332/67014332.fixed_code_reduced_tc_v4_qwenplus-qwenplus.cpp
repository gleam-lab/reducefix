#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    ll tri = 0; // count how many attacks have been made since last triple attack

    for (ll h : H) {
        // We simulate the attack process more accurately
        while (h > 0) {
            T++;
            tri++;

            if (tri == 3) {
                tri = 0;
                h -= 3;
            } else {
                h -= 1;
            }
        }

        // Reset the counter when moving to the next enemy
        tri = 0;
    }

    cout << T << "\n";
}