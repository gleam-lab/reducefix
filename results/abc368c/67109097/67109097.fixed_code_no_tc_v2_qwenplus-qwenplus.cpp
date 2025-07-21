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

    // We simulate the process using a queue to represent attacks round by round
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        T++;
        int idx = q.front();
        q.pop();

        // Apply damage
        if (T % 3 == 0) {
            H[idx] -= 3;
        } else {
            H[idx]--;
        }

        // If enemy still has health, push it back for future attack
        if (H[idx] > 0) {
            q.push(idx);
        }
    }

    cout << T << endl;
    return 0;
}