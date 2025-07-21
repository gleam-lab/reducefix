#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sizesA(n), sizesB(n - 1);
    
    // Reading the sizes of toys and boxes
    for (int i = 0; i < n; i++) {
        cin >> sizesA[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> sizesB[i];
    }
    
    // Sorting the sizes of toys and boxes
    sort(sizesA.begin(), sizesA.end());
    sort(sizesB.begin(), sizesB.end());
    
    // The maximum size of boxes that can contain all toys
    int maxBoxSize = 0;
    
    // Iterate over each toy and find the maximum box size that can contain it
    for (int i = 0; i < n; i++) {
        // We use binary search to find the smallest box that can contain the current toy
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (sizesB[m] >= sizesA[i]) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        // If no box can contain the current toy, it's impossible to store all toys
        if (r < 0) {
            cout << -1 << endl;
            return 0;
        }
        // Update the maximum box size needed
        maxBoxSize = max(maxBoxSize, sizesB[r]);
    }
    
    // Output the minimum box size needed
    cout << maxBoxSize << endl;
    return 0;
}