#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    
    // Read toy sizes and box sizes
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }
    
    // Sort toy and box sizes
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    // Iterate over toy sizes
    for (int i = 0; i < n; i++) {
        bool isPossible = false;
        for (int j = 0; j < n - 1; j++) {
            // Check if the current box size is sufficient for the current toy
            if (vb[j] >= va[i]) {
                isPossible = true;
                break;
            }
        }
        // If no box size is sufficient, the toy size is the smallest box size needed
        if (!isPossible) {
            cout << va[i] << endl;
            return 0;
        }
    }
    
    // If all toys fit in the existing boxes and toy sizes, no new box is needed
    cout << -1 << endl;
    return 0;
}