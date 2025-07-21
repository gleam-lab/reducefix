#include <bits/stdc++.h>
using namespace std;

bool canFit(const vector<int>& toys, const vector<int>& boxes, int size) {
    priority_queue<int> pq(boxes.rbegin(), boxes.rend()); // Max heap for boxes
    for (int toy : toys) {
        while (!pq.empty() && pq.top() < toy) {
            pq.pop();
        }
        if (pq.empty()) return false;
        pq.pop(); // Remove the used box
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> toys(n), boxes(n-1);
    for (int i = 0; i < n; ++i) cin >> toys[i];
    for (int i = 0; i < n-1; ++i) cin >> boxes[i];

    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    int low = toys.back(), high = 1e9;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canFit(toys, boxes, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (low == toys.back()) cout << -1 << '\n';
    else cout << low << '\n';

    return 0;
}