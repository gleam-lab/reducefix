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

    // We'll use a queue to process attacks
    queue<pair<long long, int>> q;

    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            q.push({H[i], i});
        }
    }

    while (!q.empty()) {
        auto [health, index] = q.front();
        q.pop();

        T++;

        // If T is multiple of 3, attack power is 3, else 1
        long long damage = (T % 3 == 0) ? 3 : 1;

        if (health - damage > 0) {
            // Enemy still has health left, push back to queue
            q.push({health - damage, index});
        }
    }

    cout << T << endl;
    return 0;
}