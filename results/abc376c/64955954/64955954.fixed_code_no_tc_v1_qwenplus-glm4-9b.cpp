#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> boxes[i];
    }
    
    // Sort the toys and boxes to make comparison easier
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());
    
    // Initialize the minimum box size to a very large value
    int min_box_size = INT_MAX;
    
    // We only need to check if there exists a box size that can fit all toys
    // and is the smallest possible. We do this by checking the largest toy size
    // and making sure there is a box that can fit it.
    for (int i = n - 1; i >= 0; --i) {
        // If the current box size is greater than or equal to the largest toy size,
        // then all toys can fit in a box of this size.
        if (boxes[i] >= toys[n - 1]) {
            min_box_size = min(min_box_size, boxes[i]);
            break; // No need to check further, we found the smallest possible box
        }
    }
    
    // If we found a valid box size, print it, otherwise print -1
    if (min_box_size != INT_MAX) {
        cout << min_box_size << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}