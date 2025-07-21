#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    
    // Pair toys and boxes with their original indices and sort by size
    vector<pair<int, int>> toys(n), boxes(n - 1);
    for (int i = 0; i < n; i++) {
        toys[i] = {A[i], i};
    }
    for (int i = 0; i < n - 1; i++) {
        boxes[i] = {B[i], i};
    }
    
    sort(toys.rbegin(), toys.rend());
    sort(boxes.rbegin(), boxes.rend());
    
    int lastToyIndex = 0; // Index of the last toy that fits in the first box
    int lastBoxIndex = 0; // Index of the last box that can fit a toy
    
    // Iterate over box sizes
    while (lastBoxIndex < n - 1 && toys[lastToyIndex].first <= boxes[lastBoxIndex].first) {
        if (toys[lastToyIndex].second > boxes[lastBoxIndex].second) {
            // If the smallest toy not yet placed cannot fit in the current box, print -1
            cout << -1 << endl;
            return 0;
        }
        // Move to the next toy and box
        lastToyIndex++;
        lastBoxIndex++;
    }
    
    // If all toys have been placed in existing boxes or the next box is large enough for the largest toy
    if (lastToyIndex == n || toys.back().first <= boxes[lastBoxIndex].first) {
        cout << boxes[lastBoxIndex].first << endl;
    } else {
        // Otherwise, the next box needs to be larger than the largest toy
        cout << toys.back().first + 1 << endl;
    }
    
    return 0;
}