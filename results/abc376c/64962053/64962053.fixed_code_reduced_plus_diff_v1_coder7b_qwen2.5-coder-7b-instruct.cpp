#include <bits/stdc++.h>
using namespace std;

bool canFit(const vector<int>& toys, const vector<int>& boxes, int size) {
    priority_queue<int, vector<int>, greater<int>> pq(toys.begin(), toys.end());
    for(int b : boxes) {
        if(b >= size && !pq.empty()) {
            int t = pq.top();
            pq.pop();
            if(t > b) return false;
        } else if(b < size) return false;
    }
    return pq.empty();
}

int main() {
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n - 1);
    for(int i = 0; i < n; ++i) cin >> toys[i];
    for(int i = 0; i < n - 1; ++i) cin >> boxes[i];

    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    int l = 1, r = 1e9 + 10;
    while(l < r) {
        int m = (l + r) / 2;
        if(canFit(toys, boxes, m)) r = m;
        else l = m + 1;
    }

    if(l == 1e9 + 10) cout << -1 << '\n';
    else cout << l << '\n';

    return 0;
}