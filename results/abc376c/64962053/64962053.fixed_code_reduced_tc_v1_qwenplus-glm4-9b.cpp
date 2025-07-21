#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> toys(n);
    vector<int> boxes(n - 1);
    
    for (int i = 0; i < n; i++) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> boxes[i];
    }

    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());
    
    // Step 3: Iterate over boxes and check conditions
    for (int i = 0; i < n - 1; i++) {
        // Check if all toys can fit into the current box size
        bool canFit = true;
        for (int j = 0; j < n; j++) {
            if (toys[j] > boxes[i]) {
                canFit = false;
                break;
            }
        }
        if (canFit) {
            cout << boxes[i] << endl;
            return 0;
        }
    }
    
    // Step 4: No box can fit all toys, find the smallest x such that A_n can fit
    int smallestX = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (boxes[i] < toys[n - 1]) {
            smallestX = min(smallestX, toys[n - 1]);
        }
    }
    
    if (smallestX == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << smallestX + 1 << endl; // +1 to get the smallest possible x
    }
    
    return 0;
}