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

    // Priority queue to process enemies in optimal attack order
    // We'll use max-heap (negative values for min-heap emulation)
    priority_queue<pair<long long, int>> pq;

    // Initialize the queue with how many attacks each enemy needs to die
    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            // Each enemy can be attacked every 3 turns
            // Estimate how many attacks are needed and when it will be processed
            long long attacks_needed = (H[i] + 2) / 3; // ceil division by 3
            pq.push({-attacks_needed, i});
        }
    }

    while (!pq.empty()) {
        auto [neg_attacks, idx] = pq.top();
        pq.pop();

        long long attacks_needed = -neg_attacks;

        // The earliest time we can finish attacking this enemy is at time = 3 * attacks_needed
        // But we might have already passed that time
        // So we need to calculate when this enemy should be attacked next

        // Find how many times we've attacked this enemy already
        long long prev_attacks = attacks_needed - ((H[idx] + 2) / 3);

        // Calculate the time of the next attack on this enemy
        long long next_attack_time = 3 * (prev_attacks + 1);
        T = max(T, next_attack_time);

        // Reduce the health accordingly
        H[idx] -= 3;
        
        // If still has health, push back into queue
        if (H[idx] > 0) {
            long long remaining_attacks = (H[idx] + 2) / 3;
            pq.push({-(prev_attacks + 1 + remaining_attacks), idx});
        }
    }

    cout << T << endl;
    return 0;
}