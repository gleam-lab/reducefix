#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // We will use a priority queue to always attack the strongest remaining enemy
    // We need max-heap, so we store negative values
    priority_queue<pair<long long, long long>> pq;

    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            pq.emplace(H[i], i); // Store health and position
        }
    }

    long long T = 0;

    while (!pq.empty()) {
        auto [health, pos] = pq.top();
        pq.pop();

        T++;
        if (T % 3 == 0) {
            health -= 3;
        } else {
            health -= 1;
        }

        if (health > 0) {
            pq.emplace(health, pos);
        }
    }

    cout << T << "\n";
    return 0;
}