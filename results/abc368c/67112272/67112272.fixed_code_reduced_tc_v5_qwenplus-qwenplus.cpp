#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // Priority queue to manage enemies needing special 3-damage attacks at T%3==0
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    rep(i, n) {
        ll h = H[i];
        ll attacks = 0;

        // While the enemy still has health left
        while (h > 0) {
            T++;

            // If T is multiple of 3, we can deal 3 damage
            if (T % 3 == 0) {
                if (!pq.empty() && pq.top() < T) {
                    // There's an older enemy waiting that should get this 3-damage attack
                    h += pq.top() - T; // Adjust health accordingly
                    pq.pop();
                    continue;
                }
                h -= 3;
            } else {
                // Deal normal 1-damage attack
                h -= 1;
            }

            // If not finished, push back for future 3-damage opportunity
            if (h > 0) pq.push(T);
        }

        // If there are enemies waiting and current T matches 3-damage window
        while (!pq.empty() && T % 3 != 0 && H[i] > 0) {
            T++;
            H[i] -= 1;
            if (H[i] > 0) pq.push(T);
        }
    }

    // Process remaining enemies in queue
    while (!pq.empty()) {
        T++;
        if (T % 3 == 0) {
            // Deal 3-damage
            pq.pop(); // One enemy finishes with this 3-damage
            while (!pq.empty() && T % 3 != 0) {
                T++;
                if (T % 3 == 0) pq.pop();
            }
        }
    }

    cout << T << endl;
    return 0;
}