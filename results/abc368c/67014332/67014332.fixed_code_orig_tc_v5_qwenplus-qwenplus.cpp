#include <bits/stdc++.h>
using namespace std;
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

    // To simulate the attack process efficiently, we track when each enemy dies
    // We simulate time T and maintain a queue of enemies that are currently being attacked
    // When an enemy's health reaches 0 or less, we remove it from the queue

    deque<pair<ll, ll>> enemies; // {index, remaining_health}
    for (ll i = 0; i < n; ++i) {
        enemies.push_back({i, H[i]});
    }

    ll T = 0;
    while (!enemies.empty()) {
        T++;

        auto& [idx, h] = enemies.front();
        if (T % 3 == 0) {
            h -= 3;
        } else {
            h -= 1;
        }

        if (h <= 0) {
            enemies.pop_front(); // Enemy defeated
        }
    }

    cout << T << "\n";
}