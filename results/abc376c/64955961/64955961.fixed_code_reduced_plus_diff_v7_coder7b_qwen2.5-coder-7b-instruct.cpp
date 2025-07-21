#include <bits/stdc++.h>

using namespace std;

bool canPlaceAllToys(vector<int>& toys, vector<int>& boxes, int x) {
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    int i = 0, j = 0;
    while (i < toys.size() && j < boxes.size()) {
        if (toys[i] <= boxes[j]) {
            i++;
        }
        j++;
    }

    return i == toys.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> toys(n), boxes(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> boxes[i];
    }

    int left = *max_element(toys.begin(), toys.end());
    int right = 1e9;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlaceAllToys(toys, boxes, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}