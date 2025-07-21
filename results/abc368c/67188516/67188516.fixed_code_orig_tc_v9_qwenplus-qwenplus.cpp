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

    // We'll use a priority queue to always attack the enemy with highest current health
    // Each element is {current_health, index}
    using pii = pair<long long, int>;
    priority_queue<pii> pq;

    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            pq.emplace(H[i], i);
        }
    }

    long long T = 0;
    while (!pq.empty()) {
        ++T;
        auto [health, idx] = pq.top();
        pq.pop();

        // Deal damage
        if (T % 3 == 0) {
            health -= 3;
        } else {
            health -= 1;
        }

        H[idx] = health;
        if (health > 0) {
            pq.emplace(health, idx);
        }
    }

    cout << T << "\n";
    return 0;
}