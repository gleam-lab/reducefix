#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);
    
    for (int i = 0; i < n; i++) 
        cin >> va[i];
    for (int i = 0; i < n - 1; i++) 
        cin >> vb[i];
    
    // Sort the toy sizes and box sizes
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    // Initialize the result as -1 (not found yet)
    int result = -1;
    
    // Check if we can fit each toy into the existing boxes or the new box
    for (int i = 0; i < n; i++) {
        // Try to place toy i into one of the existing boxes
        bool placed = false;
        for (int j = 0; j < n - 1; j++) {
            if (va[i] <= vb[j]) {
                placed = true;
                break;
            }
        }
        
        // If toy i cannot fit into any existing box, it needs to go into the new box
        if (!placed) {
            result = va[i];  // The new box must be at least this big
            break;
        }
    }
    
    cout << result << endl;
    return 0;
}