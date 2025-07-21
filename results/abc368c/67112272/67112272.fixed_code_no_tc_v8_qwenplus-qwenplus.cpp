#include <bits/stdc++.h>
using namespace std;

using ll = long_cast<long>;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll T = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    // Initialize the priority queue with initial health and position
    for (int i = 0; i < n; ++i) {
        if (h[i] > 0) {
            pq.emplace(h[i], i);
        }
    }

    while (!pq.empty()) {
        auto [health, idx] = pq.top();
        pq.pop();

        T++;

        // Attack logic: decrease by 3 if T is multiple of 3, else decrease by 1
        if (T % 3 == 0) {
            health -= 3;
        } else {
            health -= 1;
        }

        if (health > 0) {
            pq.emplace(health, idx);
        }
    }

    cout << T << endl;
    return 0;
}