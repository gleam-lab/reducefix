#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);
    
    // Reading input
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];
    
    // Sorting both vectors in descending order
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());
    
    // The minimum box size x
    int min_x = -1;
    
    // Iterate over each toy size
    for (int i = 0; i < n; i++) {
        bool canPlace = false;
        
        // Check if the current toy can fit in any of the existing boxes
        for (int j = 0; j < i; j++) {
            if (va[i] <= vb[j]) {
                canPlace = true;
                break;
            }
        }
        
        // If the toy cannot be placed in any existing box, the new box size must be va[i]
        if (!canPlace) {
            min_x = va[i];
            break;
        }
    }
    
    // Output the result
    cout << (min_x != -1 ? min_x : -1) << endl;
    
    return 0;
}