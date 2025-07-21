#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> enemies(N);
    for(int i = 0; i < N; i++) {
        cin >> enemies[i];
    }

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < N; i++) {
        pq.push({enemies[i], i});
    }

    long long time = 0;
    while(!pq.empty()) {
        auto [health, idx] = pq.top();
        pq.pop();

        if(health <= 0) continue;

        time++;
        health -= (time % 3 == 0 ? 3 : 1);

        pq.push({health, idx});
    }

    cout << time << endl;
    return 0;
}