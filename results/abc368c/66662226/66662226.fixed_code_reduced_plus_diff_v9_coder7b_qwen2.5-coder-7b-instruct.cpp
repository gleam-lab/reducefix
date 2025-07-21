#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    long long time = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        if (h[i] > 0) pq.push({h[i], i});
    }

    while (!pq.empty()) {
        auto [health, index] = pq.top();
        pq.pop();

        if (health <= 0) continue;

        health -= (time % 3 == 0 ? 3 : 1);
        if (health > 0) pq.push({health, index});

        time++;
    }

    cout << time << endl;
    return 0;
}