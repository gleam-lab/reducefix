#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    // Priority queue to simulate the process correctly
    // We use a min-heap to always attack the earliest enemy that is still alive
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    for (int i = 0; i < n; ++i) {
        if (H[i] > 0) {
            pq.emplace(1, i);  // First attack at time T=1 on this enemy
        }
    }

    while (!pq.empty()) {
        auto [t, idx] = pq.top();
        pq.pop();

        T = t;
        H[idx] -= (t % 3 == 0 ? 3 : 1);

        if (H[idx] > 0) {
            pq.emplace(t + 1, idx);
        } else if (idx + 1 < n && H[idx + 1] > 0) {
            pq.emplace(t + 1, idx + 1);
        }
    }

    cout << T << '\n';

    return 0;
}