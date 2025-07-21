#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    priority_queue<pair<long long, int>> pq;
    for(int i = 0; i < n; i++) {
        pq.push({-h[i], i});
    }

    long long ans = 0;
    long long time = 0;
    while(!pq.empty()) {
        auto [health, idx] = pq.top();
        pq.pop();

        if(health == 0) continue;

        time++;
        if(time % 3 == 0) {
            h[idx] -= 3;
        } else {
            h[idx]--;
        }

        if(h[idx] != 0) {
            pq.push({-h[idx], idx});
        }

        ans = max(ans, time);
    }

    cout << ans << endl;

    return 0;
}