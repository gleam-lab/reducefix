#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // We'll use a queue to simulate the attack process
    queue<pair<ll, ll>> q; // pair: (current_health, time_when_will_be_attacked_next)

    // Initialize queue with all enemies
    rep(i, n) {
        if (H[i] > 0) {
            q.push({H[i], 1}); // First attack happens at T+1
        }
    }

    while (!q.empty()) {
        auto [health, nextAttackTime] = q.front();
        q.pop();

        T = nextAttackTime;

        // Calculate how much damage will be dealt at this time
        ll damage = (T % 3 == 0) ? 3 : 1;
        health -= damage;

        if (health > 0) {
            // Enemy still alive, schedule next attack
            q.push({health, T + 1});
        }
    }

    cout << T << endl;
}