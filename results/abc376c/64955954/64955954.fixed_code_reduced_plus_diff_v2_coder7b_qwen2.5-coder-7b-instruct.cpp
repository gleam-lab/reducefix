#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> va(n);
    vector<int> vb(n - 1);
    
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];
    
    // Sort the arrays
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    // Check if the largest toy can fit into any of the boxes
    for (int i = 0; i < n - 1; ++i) {
        if (va[n - 1] <= vb[i]) {
            cout << vb[i] << endl;
            return 0;
        }
    }
    
    // If the largest toy cannot fit into any of the boxes, output -1
    cout << -1 << endl;
    
    return 0;
}