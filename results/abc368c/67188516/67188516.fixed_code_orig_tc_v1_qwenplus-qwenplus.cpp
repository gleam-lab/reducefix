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

    // We will simulate the process with a priority queue.
    // Each enemy is represented by its current health and position (index)
    // Since we always attack the frontmost alive enemy, we can simply iterate through them in order

    long long T = 0;
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        if (h <= 0) continue;

        while (h > 0) {
            ++T;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }

    cout << T << "\n";
    return 0;
}