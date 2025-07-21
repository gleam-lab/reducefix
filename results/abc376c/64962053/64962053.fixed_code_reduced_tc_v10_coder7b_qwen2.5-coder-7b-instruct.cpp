#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];
    
    // Sort the toy sizes and box sizes
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    // Check if we can place all toys into the boxes
    for (int i = 0; i < n; ++i) {
        if (va[i] > vb[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    // The size of the last box used
    cout << vb[n - 2] + 1 << endl;
    
    return 0;
}