#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> toys(n), boxes(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> boxes[i];
    }
    
    // Sort the toys and boxes
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());
    
    // Initialize the minimum box size to a very large value
    long long min_box_size = LLONG_MAX;
    
    // Iterate through each toy to find the minimum box size it can fit into
    for (int i = 0; i < n; ++i) {
        // Check if toys[i] can fit into any of the existing boxes
        bool can_fit = false;
        for (int j = 0; j < n - 1; ++j) {
            if (toys[i] <= boxes[j]) {
                // Update the minimum box size and break since toys[i] can fit into boxes[j]
                min_box_size = min(min_box_size, boxes[j]);
                can_fit = true;
                break;
            }
        }
        if (!can_fit) {
            // If no box can fit the toy, print -1 and exit
            cout << -1 << endl;
            return 0;
        }
    }
    
    // Output the minimum box size
    cout << min_box_size << endl;
    return 0;
}