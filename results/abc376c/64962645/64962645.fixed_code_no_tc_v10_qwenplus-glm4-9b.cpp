#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n - 1);
    
    // Reading toy sizes and sorting them in descending order
    for (int i = 0; i < n; i++) {
        cin >> toys[i];
    }
    sort(toys.begin(), toys.end(), greater<int>());
    
    // Reading box sizes and sorting them in ascending order
    for (int i = 0; i < n - 1; i++) {
        cin >> boxes[i];
    }
    sort(boxes.begin(), boxes.end());
    
    // Finding the minimum box size that can accommodate the largest toy
    int min_box_size = 0;
    for (int i = 0; i < n; i++) {
        if (boxes[i] >= toys[i]) {
            min_box_size = boxes[i];
        } else {
            // If no box can accommodate the current toy, print -1 and exit
            cout << -1 << endl;
            return 0;
        }
    }
    
    // The minimum box size needed to accommodate all toys
    cout << min_box_size << endl;
    return 0;
}