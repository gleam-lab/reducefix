#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> boxes[i];
    }
    
    // Sort the toy sizes and the box sizes
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());
    
    // Pointer to the current box we are considering
    int boxIndex = 0;
    // Variable to store the minimum box size needed
    int minBoxSize = 0;
    // Variable to store the current maximum size of the boxes we have considered
    int currentMaxBoxSize = 0;
    
    for (int i = 0; i < n; i++) {
        // If the current toy is larger than the current box size, we need a new box
        while (boxIndex < n - 1 && toys[i] > boxes[boxIndex]) {
            currentMaxBoxSize = max(currentMaxBoxSize, boxes[boxIndex]);
            boxIndex++;
        }
        
        // If we have considered all boxes and still cannot place the toy, return -1
        if (boxIndex == n - 1 && toys[i] > currentMaxBoxSize) {
            cout << -1 << endl;
            return 0;
        }
        
        // Update the minimum box size needed
        minBoxSize = max(minBoxSize, toys[i]);
    }
    
    // Output the minimum box size needed
    cout << minBoxSize << endl;
    
    return 0;
}