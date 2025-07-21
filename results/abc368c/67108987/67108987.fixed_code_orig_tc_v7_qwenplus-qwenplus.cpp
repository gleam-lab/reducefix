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

    long long T = 0;
    // We simulate the process while maintaining a queue of enemies with remaining health > 0
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        T++;
        int idx = q.front();
        // If T is multiple of 3, attack deals 3 damage, else 1
        long long damage = (T % 3 == 0) ? 3 : 1;
        H[idx] -= damage;
        if (H[idx] <= 0) {
            q.pop();
        } else if (idx + 1 < N && H[idx + 1] > 0) {
            // If next enemy exists and has health left, it's already in the queue
            // Just keep processing
        } else {
            // Add next alive enemy to queue
            for (int j = idx + 1; j < N; ++j) {
                if (H[j] > 0) {
                    q.push(j);
                    break;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}