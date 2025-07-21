#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;

    // Priority queue to track enemies with health > 0, sorted by current position
    // Each element is a pair: (current time until triple attack available, index)
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;

    // Initialize the priority queue
    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            // First time we can attack this enemy with a triple hit (when T % 3 == 0)
            long long firstTripleHitTime = (3 - (T % 3)) % 3;
            pq.emplace(firstTripleHitTime, i);
        }
    }

    while (!pq.empty()) {
        auto [t, idx] = pq.top();
        pq.pop();

        T = t + 1;

        // Apply damage
        if (H[idx] <= 0) continue;

        if (T % 3 == 0) {
            H[idx] -= 3;
        } else {
            H[idx] -= 1;
        }

        // If enemy still has health, schedule next attack
        if (H[idx] > 0) {
            pq.emplace(T + 1, idx);
        }
    }

    cout << T << endl;
    return 0;
}