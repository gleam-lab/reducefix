#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& toys, vector<int>& boxes, int x) {
    priority_queue<int> pq(toys.begin(), toys.end()); // Max heap for toys
    set<int> availableBoxes(boxes.begin(), boxes.end()); // Set for available boxes

    while (!pq.empty()) {
        int currentToy = pq.top();
        pq.pop();

        auto it = availableBoxes.lower_bound(currentToy); // Find first box >= currentToy

        if (it == availableBoxes.end() && x < currentToy) {
            return false; // No suitable box found even with the largest possible box
        }

        if (it == availableBoxes.end()) {
            availableBoxes.insert(x); // Insert the largest possible box
        } else {
            availableBoxes.erase(it); // Remove used box
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n-1);

    for (int i = 0; i < n; ++i) cin >> toys[i];
    for (int i = 0; i < n-1; ++i) cin >> boxes[i];

    sort(toys.begin(), toys.end(), greater<int>()); // Sort toys in descending order
    sort(boxes.begin(), boxes.end()); // Sort boxes in ascending order

    int low = 0, high = *max_element(toys.begin(), toys.end()), ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlace(toys, boxes, mid)) {
            ans = mid;
            high = mid - 1; // Try to minimize the box size
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}