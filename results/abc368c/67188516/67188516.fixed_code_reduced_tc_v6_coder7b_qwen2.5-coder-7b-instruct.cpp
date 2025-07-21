#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long T = 0;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < N; i++) {
        pq.push({-H[i], i});
    }

    while(!pq.empty()) {
        auto [health, index] = pq.top();
        pq.pop();

        T++;
        if(T % 3 == 0) {
            H[index] -= 3;
        } else {
            H[index]--;
        }

        if(H[index] > 0) {
            pq.push({-H[index], index});
        }
    }

    cout << T << endl;

    return 0;
}