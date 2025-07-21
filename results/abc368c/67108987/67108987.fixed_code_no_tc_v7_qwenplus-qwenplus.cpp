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

    // We simulate the process using a queue to track enemies that need additional attacks
    queue<int> activeEnemies;

    for (int i = 0; i < N; ++i) {
        if (H[i] > 0) {
            activeEnemies.push(i);
        }
    }

    while (!activeEnemies.empty()) {
        T++;

        // Determine which attack pattern we're using this step
        bool tripleAttack = (T % 3 == 0);

        // Attack the first enemy in line
        int enemyIndex = activeEnemies.front();
        if (tripleAttack) {
            H[enemyIndex] -= 3;
        } else {
            H[enemyIndex] -= 1;
        }

        // If health is now zero or below, remove from queue
        if (H[enemyIndex] <= 0) {
            activeEnemies.pop();
        }
    }

    cout << T << endl;
    return 0;
}