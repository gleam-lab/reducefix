#include <bits/stdc++.h>

using namespace std;

bool canFit(vector<int>& sizes, int x) {
    sort(sizes.begin(), sizes.end());
    for (int i = 0; i < sizes.size(); ++i) {
        if (x < sizes[i]) return false;
        x -= sizes[i];
    }
    return true;
}

int minBoxSize(vector<int>& toys, vector<int>& boxes) {
    vector<int> allSizes(toys);
    allSizes.insert(allSizes.end(), boxes.begin(), boxes.end());
    sort(allSizes.begin(), allSizes.end());

    int left = 0, right = 1e9 + 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (canFit(allSizes, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left == 1e9 + 1 ? -1 : left;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> toys(n), boxes(n-1);
    for (int i = 0; i < n; ++i) cin >> toys[i];
    for (int i = 0; i < n-1; ++i) cin >> boxes[i];

    cout << minBoxSize(toys, boxes) << '\n';

    return 0;
}