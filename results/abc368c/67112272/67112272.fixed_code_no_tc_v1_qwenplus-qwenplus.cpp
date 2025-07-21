#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    // Initialize: next time we can use a triple attack on this enemy
    for (int i = 0; i < n; ++i) {
        if (H[i] > 0) {
            ll attacksUntilTriple = 3 - (T % 3); // Next triple attack time
            ll damage = 3;
            pq.emplace(attacksUntilTriple, i);
        }
    }

    while (!pq.empty()) {
        auto [time, idx] = pq.top();
        pq.pop();
        T = time;
        H[idx] -= 3;

        if (H[idx] > 0) {
            // Next time this enemy can be attacked with triple damage is after 3 more steps
            pq.emplace(T + 3, idx);
        } else {
            // If this enemy still has health left, continue processing
            bool allZero = true;
            for (int i = 0; i < n; ++i) {
                if (H[i] > 0) {
                    allZero = false;
                    break;
                }
            }
            if (allZero) break;
        }
    }

    cout << T << endl;
}