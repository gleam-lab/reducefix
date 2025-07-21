#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    // Initialize: store (current_attack_time, index)
    // where current_attack_time = ceil(H[i] / 1.5) since every 3 attacks do 5 damage total
    for (ll i = 0; i < n; ++i) {
        ll h = H[i];
        ll attacks_needed = (h + 4) / 5 * 3;  // Every 3 attacks do 5 damage (1+1+3)
        pq.emplace(attacks_needed, i);
    }

    while (!pq.empty()) {
        auto [attacks_needed, i] = pq.top();
        pq.pop();

        // This enemy needs to be attacked again
        // We simulate attacking until all are dead
        // Each time we process an attack at time T+1

        T += 1;
        if (T % 3 == 0) {
            H[i] -= 3;
        } else {
            H[i] -= 1;
        }

        if (H[i] > 0) {
            // Need to attack this enemy again
            ll remaining_attacks = (H[i] + 4) / 5 * 3;
            pq.emplace(T + remaining_attacks, i);
        }
    }

    cout << T << endl;
    return 0;
}