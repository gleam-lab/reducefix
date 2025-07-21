#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& toys, vector<int>& boxes, int size) {
    int i = 0, j = 0;
    while (i < toys.size() && j < boxes.size()) {
        if (toys[i] <= size && toys[i] <= boxes[j]) {
            i++;
        } else {
            j++;
        }
    }
    return i == toys.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n - 1);
    for (int i = 0; i < n; ++i) cin >> toys[i];
    for (int i = 0; i < n - 1; ++i) cin >> boxes[i];

    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    int left = 0, right = 1e9 + 10, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canPlace(toys, boxes, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}