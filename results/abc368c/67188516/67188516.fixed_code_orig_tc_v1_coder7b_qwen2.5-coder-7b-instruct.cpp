#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long solve(int n, vector<int>& h) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({h[i], i});
    }

    long long ans = 0, time = 0;
    while (!pq.empty()) {
        auto [hp, idx] = pq.top(); pq.pop();
        hp -= (time % 3 == 0 ? 3 : 1);
        if (hp > 0) {
            pq.push({hp, idx});
        } else {
            ans += time + 1;
        }
        ++time;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    cout << solve(n, h) << '\n';

    return 0;
}