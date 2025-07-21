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

    // We will simulate the process using a queue
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        ++T;
        if (T % 3 == 0) {
            H[idx] -= 3;
        } else {
            H[idx] -= 1;
        }

        if (H[idx] > 0) {
            q.push(idx); // enemy still alive, push back to queue
        }
    }

    cout << T << endl;
    return 0;
}