#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> vb[i];
    }
    
    // Sort both vectors in descending order
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());
    
    // Create a vector to hold cumulative maximum sizes for vb
    vector<int> max_vb(n - 1);
    max_vb[0] = vb[0];
    for (int i = 1; i < n - 1; ++i) {
        max_vb[i] = max(max_vb[i - 1], vb[i]);
    }
    
    // Check if there is a valid box size x that can be used to fit all toys
    for (int i = 0; i < n; ++i) {
        int toy_size = va[i];
        // Binary search for the smallest box size in vb that is not less than toy_size
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (vb[mid] >= toy_size) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        // Check if the found box size is not less than toy_size and is the smallest possible
        if (vb[left] >= toy_size) {
            cout << vb[left] << endl;
            return 0;
        }
    }
    
    // If no valid box size is found, print -1
    cout << -1 << endl;
    return 0;
}