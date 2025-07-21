#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> va(n), vb(n - 1);
    
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];
    
    set<int> possibleBoxSizes;
    
    // Adding all initial box sizes to possibleBoxSizes
    for (int i = 0; i < n - 1; i++) {
        possibleBoxSizes.insert(vb[i]);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        auto it = possibleBoxSizes.upper_bound(va[i]); // Get the smallest element greater than va[i]
        
        if (it != possibleBoxSizes.end()) {
            // If there is at least one box that can be used to place toy va[i]
            cout << *it << endl;
            return 0;
        } else {
            // If no box can be used, print -1 and exit
            cout << -1 << endl;
            return 0;
        }
    }
    
    // If all toys have been considered and no box can be used, this point should not be reached
    return 0;
}