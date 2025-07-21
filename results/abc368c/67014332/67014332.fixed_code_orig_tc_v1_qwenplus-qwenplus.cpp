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

    // We will simulate the attack process efficiently using a priority queue
    // Each enemy is represented by its current health and its position
    // Since we always attack the frontmost enemy with health > 0, we can use a queue to manage enemies

    deque<pair<ll, ll>> dq;  // {health, index}
    for (ll i = 0; i < n; ++i) {
        if (H[i] > 0) {
            dq.emplace_back(H[i], i);
        }
    }

    ll T = 0;

    while (!dq.empty()) {
        ++T;
        auto& front = dq.front();
        front.first -= (T % 3 == 0) ? 3 : 1;

        if (front.first <= 0) {
            dq.pop_front();
        }
    }

    cout << T << "\n";
    return 0;
}