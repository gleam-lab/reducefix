#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;

// Function to calculate how many attacks are needed to reduce a single enemy's health to 0 or less
ll compute_attacks(ll h) {
    // Binary search on T: find the minimal T such that total damage >= h
    ll low = 1, high = 2 * h; // upper bound on T
    while (low < high) {
        ll mid = (low + high) / 2;
        // Number of triple attacks at multiples of 3 in [1..mid]
        ll triple = mid / 3;
        // Total damage = triple * 3 + (mid - triple) * 1
        ll damage = triple * 2 + mid; // since 3*triple + (mid - triple) = triple*2 + mid
        if (damage >= h)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    // We simulate the process with priority queue to always attack enemies that still have health > 0
    // The priority queue will store pairs of (health, index), prioritized by health descending
    priority_queue<pair<ll, int>> pq;
    rep(i, n) {
        if (h[i] > 0)
            pq.push({h[i], i});
    }

    ll time = 0;
    while (!pq.empty()) {
        time++;
        auto [health, idx] = pq.top();
        pq.pop();

        // Apply the correct damage based on current time
        if (time % 3 == 0)
            health -= 3;
        else
            health -= 1;

        if (health > 0)
            pq.push({health, idx});
    }

    cout << time << endl;
}