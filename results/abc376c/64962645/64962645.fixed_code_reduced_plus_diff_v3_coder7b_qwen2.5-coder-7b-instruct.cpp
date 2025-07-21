#include <bits/stdc++.h>
using namespace std;

bool canPlaceToys(vector<int>& toys, vector<int>& boxes, int x) {
    int n = toys.size();
    vector<int> used(n + 1, false);
    for (int i = 0; i < n; ++i) {
        if (toys[i] <= x) {
            for (int j = 0; j < n - 1; ++j) {
                if (!used[j] && boxes[j] >= toys[i]) {
                    used[j] = true;
                    break;
                }
            }
        }
    }
    return accumulate(used.begin(), used.end(), 0) == n;
}

int main() {
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n - 1);
    for (int i = 0; i < n; ++i) cin >> toys[i];
    for (int i = 0; i < n - 1; ++i) cin >> boxes[i];

    sort(toys.begin(), toys.end());
    reverse(boxes.begin(), boxes.end());

    int low = 0, high = 1e9;
    while (low < high) {
        int mid = (low + high) / 2;
        if (canPlaceToys(toys, boxes, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if (low > 1e8) cout << -1 << endl;
    else cout << low << endl;

    return 0;
}