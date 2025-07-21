#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;

    // We simulate the process using a priority queue
    // Each enemy is represented as a pair (-health, index)
    // We use a max heap to always attack the frontmost enemy with health > 0
    // We use a min-heap style with negative values to simulate max-heap

    priority_queue<pair<ll, ll>> pq;

    rep(i, n) {
        if (h[i] > 0) {
            pq.push({-h[i], i});
        }
    }

    while (!pq.empty()) {
        ans++;
        ll idx = pq.top().second;
        pq.pop();

        // Decrease health
        ll damage = (ans % 3 == 0) ? 3 : 1;
        h[idx] -= damage;

        if (h[idx] > 0) {
            pq.push({-h[idx], idx});
        }

        // Move to next enemy only if current one is still alive or queue is empty
        if (pq.empty()) {
            // If all enemies are processed, break
            bool all_zero = true;
            rep(i, n) {
                if (h[i] > 0) {
                    all_zero = false;
                    break;
                }
            }
            if (!all_zero) {
                // Reset and reinsert remaining enemies
                rep(i, n) {
                    if (h[i] > 0) {
                        pq.push({-h[i], i});
                    }
                }
            }
        }
    }

    cout << ans << endl;
}