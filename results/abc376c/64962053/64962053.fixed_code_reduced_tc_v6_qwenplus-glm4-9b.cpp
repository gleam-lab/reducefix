#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> toys(n), boxes(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> boxes[i];
    }
    
    // Merge toys and boxes into a single sorted list
    vector<pair<long long, bool>> merged(n);
    for (int i = 0; i < n; i++) {
        merged[i] = {toys[i], true};  // true for toys
    }
    for (int i = 0; i < n - 1; i++) {
        merged[n + i] = {boxes[i], false};  // false for boxes
    }
    
    // Sort the merged list
    sort(merged.begin(), merged.end());
    
    // Find the minimum size for the new box
    long long min_size = -1;
    for (int i = 0; i < 2 * n - 1; i++) {
        if (merged[i].second) {
            // Skip toys
            continue;
        }
        
        if (i == 0 || merged[i - 1].second) {
            // First box or the box after a toy
            min_size = merged[i].first;
        }
        
        if (min_size > merged[i + 1].first) {
            // Current box is smaller than the next one, update min_size
            min_size = merged[i].first;
        } else {
            // Current box is larger than or equal to the next one, cannot update min_size
            min_size = -1;
            break;
        }
    }
    
    // Output the result
    if (min_size == -1) {
        cout << -1 << endl;
    } else {
        cout << min_size + 1 << endl;  // Add 1 because we might need an additional box
    }
    
    return 0;
}