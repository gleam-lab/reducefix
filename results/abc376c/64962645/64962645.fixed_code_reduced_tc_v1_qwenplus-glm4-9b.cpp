#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n, 0);
    vector<int> vb(n - 1, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> vb[i];
    }
    
    // Sort toy sizes in descending order and box sizes in descending order
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());
    
    // Check if there are any toys that are larger than all available boxes
    for (int i = 0; i < n; ++i) {
        if (va[i] > vb[i]) {
            // If a toy is larger than the corresponding box, no valid x exists
            cout << -1 << endl;
            return 0;
        }
    }
    
    // The minimum x needed is at least the size of the largest toy
    // because the largest toy must be placed in the smallest possible box that can fit it
    cout << va[0] << endl;
    
    return 0;
}