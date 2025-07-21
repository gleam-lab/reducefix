#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& toys, vector<int>& boxes) {
    int n = toys.size();
    int m = boxes.size();

    // Sort toys and boxes in descending order
    sort(toys.begin(), toys.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());

    // Iterate through the sorted toys
    for (int i = 0; i < n; ++i) {
        // If current toy cannot fit into any available box, return false
        if (toys[i] > boxes.back()) {
            return false;
        }
        // Remove the largest box that can fit the current toy
        while (!boxes.empty() && boxes.back() >= toys[i]) {
            boxes.pop_back();
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n - 1);

    // Read toy sizes
    for (int i = 0; i < n; ++i) {
        cin >> toys[i];
    }

    // Read box sizes
    for (int i = 0; i < n - 1; ++i) {
        cin >> boxes[i];
    }

    // Check if it's possible to place all toys without needing additional boxes
    if (canPlace(toys, boxes)) {
        cout << *min_element(toys.begin(), toys.end()) << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}