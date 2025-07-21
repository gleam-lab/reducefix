#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to determine how many attacks are needed to reduce enemy health to 0 or less
ll compute_attacks(int h) {
    // We simulate the attack pattern:
    // Attacks: every T where T increases by 1 each step
    // At T % 3 == 0 => damage = 3
    // Else => damage = 1
    ll t = 0;
    while (h > 0) {
        t++;
        if (t % 3 == 0) {
            h -= 3;
        } else {
            h -= 1;
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    // Priority queue to process enemies needing more hits first
    // We'll use max-heap based on health
    priority_queue<pair<ll, int>> pq;

    // Initialize total time
    ll time = 0;

    // First, push all enemies with health > 0 into the priority queue
    for (int i = 0; i < n; ++i) {
        if (H[i] > 0) {
            // Estimate how many attacks are needed roughly as upper bound
            ll est = H[i] * 3 / 5 + 3; // rough estimate of T needed
            pq.push({-est, i}); // Min-heap by estimated time
        }
    }

    // Simulate optimal attack sequence using greedy strategy
    while (!pq.empty()) {
        auto [_, idx] = pq.top();
        pq.pop();

        time++;

        if (H[idx] <= 0) continue; // already dead

        if (time % 3 == 0) {
            H[idx] -= 3;
        } else {
            H[idx]--;
        }

        if (H[idx] > 0) {
            ll next_est = time + H[idx] * 3 / 5 + 3;
            pq.push({-next_est, idx});
        }
    }

    cout << time << endl;
}