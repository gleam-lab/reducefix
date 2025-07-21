#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    
    for(int i = 0; i < n; ++i)
        cin >> va[i];
    
    for(int i = 0; i < n-1; ++i)
        cin >> vb[i];
    
    // Sort the sizes of the toys and boxes
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    // Initialize the minimum size of the box Takahashi needs to buy
    long long minBoxSize = 0;
    
    // Iterate through the sorted sizes of the toys and boxes
    for(int i = 0; i < n; ++i) {
        // If the current toy cannot fit in any of the available boxes, return -1
        if(i == n-1 || va[i] > vb[i]) {
            if(minBoxSize == 0) {
                minBoxSize = va[i];
            } else if(va[i] <= minBoxSize) {
                continue;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    // Print the minimum size of the box Takahashi needs to buy
    cout << minBoxSize << endl;
    
    return 0;
}