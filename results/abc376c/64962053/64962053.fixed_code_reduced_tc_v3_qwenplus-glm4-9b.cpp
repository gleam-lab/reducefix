#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i) cin >> va[i];
    for (int i = 0; i < n - 1; ++i) cin >> vb[i];
    
    // Sort the toy sizes and box sizes
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    // Iterate over the boxes in reverse order
    for (int i = n - 2; i >= 0; --i) {
        // If the current box is smaller than the current toy, check the next one
        if (vb[i] < va[i]) {
            if (i == n - 2 || vb[i + 1] >= va[i + 1]) {
                // If there's no larger box available, return -1
                cout << -1 << endl;
                return 0;
            }
        } else {
            // If the current box is large enough, this is the smallest possible box size
            cout << vb[i] << endl;
            return 0;
        }
    }
    
    // If all boxes are smaller than the first toy, return -1
    cout << -1 << endl;
    return 0;
}