#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long T = 0;

    // We'll use a queue to process enemies in order
    queue<int> q;
    for (int i = 0; i < N; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        
        T++;
        
        // If T is a multiple of 3, attack with power 3, else with 1
        long long damage = (T % 3 == 0) ? 3 : 1;
        
        H[idx] -= damage;
        
        // If enemy still has health left, put it back in the queue
        if (H[idx] > 0) {
            q.push(idx);
        }
    }

    cout << T << endl;
    return 0;
}