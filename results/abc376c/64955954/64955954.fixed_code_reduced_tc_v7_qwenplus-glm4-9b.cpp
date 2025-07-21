#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> toys(n);
    vector<int> boxes(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> toys[i];
    }
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> boxes[i];
    }
    
    // Sort both toys and boxes
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());
    
    // Find the smallest box size that can accommodate all toys
    int minBoxSize = boxes[n - 2]; // Initialize with the largest box size minus one
    
    for (int i = 0; i < n; ++i) {
        if (toys[i] > minBoxSize) {
            // If any toy is larger than the largest box size, output -1
            cout << -1 << endl;
            return 0;
        }
        // Update the smallest box size
        minBoxSize = min(minBoxSize, boxes[i]);
    }
    
    cout << minBoxSize + 1 << endl; // +1 to account for the box size
    return 0;
}