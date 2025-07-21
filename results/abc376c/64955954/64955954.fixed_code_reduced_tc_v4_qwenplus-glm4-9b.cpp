#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> toys, boxes;
    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        toys.push_back(size);
    }
    for (int i = 0; i < n - 1; ++i) {
        int size;
        cin >> size;
        boxes.push_back(size);
    }

    // Sort the toy and box sizes
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    // Binary search for the minimum box size
    int left = 0, right = 1e9 + 1; // Set the upper bound higher than any possible box size
    while (left < right) {
        int mid = left + (right - left) / 2;
        int i = 0, j = 0;
        bool canFit = true;

        // Check if all toys can fit into the boxes of size mid
        while (i < n && j < n - 1) {
            if (toys[i] <= boxes[j]) {
                ++i;
            }
            ++j;
        }

        // If all toys fit, try a smaller box size
        if (i == n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    // If the left boundary is still greater than the right, it means no box can fit
    if (left > right) {
        cout << "-1" << endl;
    } else {
        cout << left << endl;
    }

    return 0;
}