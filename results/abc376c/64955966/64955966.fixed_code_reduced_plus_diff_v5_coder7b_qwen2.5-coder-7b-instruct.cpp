#include <bits/stdc++.h>

using namespace std;

bool canPlaceAllToys(vector<int>& toys, vector<int>& boxes, int mid) {
    for (int i = 0; i < toys.size(); ++i) {
        auto it = lower_bound(boxes.begin(), boxes.end(), toys[i]);
        if (it == boxes.end() || *it < toys[i]) {
            return false;
        }
    }
    return true;
}

int minBoxSize(int n, vector<int>& toys, vector<int>& boxes) {
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    int left = toys.back();
    int right = toys.back() + toys.back();
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

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> toys(N), boxes(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> toys[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> boxes[i];
    }

    int answer = minBoxSize(N, toys, boxes);
    cout << answer << endl;

    return 0;
}