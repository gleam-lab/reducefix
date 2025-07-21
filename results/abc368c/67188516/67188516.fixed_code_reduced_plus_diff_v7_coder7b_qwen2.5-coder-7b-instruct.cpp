#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(int i = 0; i < N; i++) {
        pq.push({H[i], i});
    }

    long long time = 0;
    while(!pq.empty()) {
        auto [h, idx] = pq.top();
        pq.pop();

        h -= (time % 3 == 0 ? 3 : 1);
        if(h > 0) {
            pq.push({h, idx});
        }
        time++;
    }

    cout << time << endl;
    return 0;
}