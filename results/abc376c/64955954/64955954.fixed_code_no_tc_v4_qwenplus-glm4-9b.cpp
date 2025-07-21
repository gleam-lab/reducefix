#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    
    // Read the size of toys
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    
    // Read the size of boxes
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }
    
    // Sort the box sizes to facilitate the process
    sort(vb.begin(), vb.end());
    
    // Iterate over the sorted box sizes
    for (int i = n - 2; i >= 0; i--) {
        // If there's a discrepancy between the current box size and the next larger toy size
        if (vb[i] < va[i + 1]) {
            // Output the size of the toy which is larger than the current box
            cout << va[i + 1] << endl;
            return 0;
        }
    }
    
    // If no discrepancy is found, the smallest box that can fit the largest toy
    cout << va[0] << endl;
    return 0;
}