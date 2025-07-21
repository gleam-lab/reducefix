#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // We will use a priority queue to always attack the enemy that would benefit most from a triple hit
    // The priority queue stores pairs of (-benefit, index)
    // Benefit is calculated as how much more damage the triple hit does compared to single hits
    // Triple hit does 3 damage, equivalent to 3 single hits => benefit = 2 extra damage per triple
    priority_queue<pair<long long, long long>> pq;

    long long T = 0;
    long long total_attacks = 0;
    long long n = N;

    // Initialize: each enemy can be optimized with triple attacks
    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            long long full_triples = H[i] / 3;
            long long leftover = H[i] % 3;
            long long benefit = full_triples * 2 + (leftover > 0 ? leftover : 0);
            pq.emplace(benefit, i);
        }
    }

    // We simulate using greedy strategy:
    // Try to use triple attacks where they give maximum benefit
    // When we use a triple attack, we reduce the health and reinsert into PQ if still alive

    // Store remaining health
    vector<long long> remaining = H;

    while (!pq.empty()) {
        auto [benefit, idx] = pq.top();
        pq.pop();

        if (remaining[idx] <= 0) continue; // Already defeated

        // Use one triple attack
        remaining[idx] -= 3;
        T += 1;

        // Recalculate benefit if this enemy is still alive
        if (remaining[idx] > 0) {
            long long full_triples = remaining[idx] / 3;
            long long leftover = remaining[idx] % 3;
            long long new_benefit = full_triples * 2 + (leftover > 0 ? leftover : 0);
            pq.emplace(new_benefit, idx);
        }
    }

    // Any remaining enemies not fully processed can be finished with single attacks
    // But our greedy approach should have already handled all
    cout << T << endl;

    return 0;
}