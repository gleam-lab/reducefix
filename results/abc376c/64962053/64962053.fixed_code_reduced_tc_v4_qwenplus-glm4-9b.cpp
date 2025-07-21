#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }
    
    // Find the smallest toy size that is not less than the largest box size
    int validToySize = INT_MAX;
    for (int i = 0; i < n; i++) {
        bool isPossible = true;
        for (int j = 0; j < n - 1; j++) {
            if (vb[j] < va[i]) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            validToySize = min(validToySize, va[i]);
        }
    }
    
    // If no such toy size exists, return -1
    if (validToySize == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    
    // Otherwise, return the size of the largest box if that's the smallest valid toy size,
    // otherwise return the smallest valid toy size
    cout << (validToySize == vb[n-1] ? vb[n-1] : validToySize) << endl;
    
    return 0;
}