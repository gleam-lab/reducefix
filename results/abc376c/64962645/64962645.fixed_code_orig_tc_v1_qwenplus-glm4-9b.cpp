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
    
    // Sort toys in descending order
    sort(toys.rbegin(), toys.rend());
    // Sort boxes in descending order
    sort(boxes.rbegin(), boxes.rend());
    
    int minBoxSize = 0;
    
    for (int i = 0; i < n; ++i) {
        // For each toy, check the minimum box size that can hold it
        // It should be equal to or greater than the last box size
        // that was able to hold the previous toys.
        minBoxSize = max(minBoxSize, boxes[i]);
        
        // If at any point, the toy size is greater than the available box size,
        // it's impossible to place the toys in the boxes as required.
        if (toys[i] > minBoxSize) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    // The minimum box size that can hold all toys is the answer
    cout << minBoxSize << endl;
    return 0;
}