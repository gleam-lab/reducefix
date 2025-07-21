#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // We will simulate the process efficiently using a priority queue
    // but track how many attacks are needed at each T value

    // We'll maintain a priority queue of enemies that still have health > 0,
    // prioritized by their position (frontmost first)

    // To simulate attacks, we need to know when T is a multiple of 3

    // Instead of simulating every step, which would be too slow,
    // we can use a greedy approach with a priority queue

    // Let's use a deque to represent enemies in order
    deque<pair<long long, long long>> enemies; // {health, index}
    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            enemies.push_back({H[i], i});
        }
    }

    long long T = 0;
    long long current_time = 0;
    long long processed_enemies = 0;

    // We'll use a multiset to keep track of attack times
    // and calculate when an enemy needs to be attacked again
    // based on whether the attack time is divisible by 3

    // The key idea is to determine how many attacks it takes
    // to reduce an enemy's health to 0 or less, considering:
    // - Every 3rd attack does 3 damage
    // - All others do 1 damage

    // Precompute the number of attacks required for each health value
    // For this we define a function to compute attacks needed

    auto attacks_needed = [](long long h) -> long long {
        // Binary search to find minimum x such that:
        // number of multiples of 3 in [1..x] * 3 + remaining attacks = h
        long long low = 0, high = 2e18;
        while (low < high) {
            long long mid = (low + high) / 2;
            long long triple_attacks = mid / 3;
            long long single_attacks = mid - triple_attacks;
            long long total_damage = triple_attacks * 3 + single_attacks;
            if (total_damage >= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    };

    // Since enemies are processed in order, we can simulate more efficiently
    // by computing how much damage they receive until they are dead
    // and removing them from the front

    vector<long long> enemy_damage(N, 0);

    for (int i = 0; i < N; ++i) {
        if (H[i] == 0) continue;

        // Compute how many attacks this enemy needs to die
        long long att = attacks_needed(H[i]);
        T += att;
        // Each attack after this one will be shifted by att
        // so for every enemy j > i, their attack count is offset
        // but since we attack frontmost alive enemy, we must simulate differently

        // This naive approach doesn't work correctly due to sequential nature
        // So let's try a different method
    }

    // Better approach: simulate with a queue tracking enemies that still have HP > 0
    // and calculate how much damage they receive per round

    deque<int> q;
    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            q.push_back(i);
        }
    }

    T = 0;
    while (!q.empty()) {
        T++;
        int idx = q.front();
        if (T % 3 == 0) {
            H[idx] -= 3;
        } else {
            H[idx] -= 1;
        }
        if (H[idx] <= 0) {
            q.pop_front();
        }
    }

    cout << T << endl;

    return 0;
}