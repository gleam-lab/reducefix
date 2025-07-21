#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    
    // Read sizes of toys and boxes
    for(int i = 0; i < n; ++i)
        cin >> va[i];
    for(int i = 0; i < n-1; ++i)
        cin >> vb[i];

    // Sort both arrays
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Check if the largest toy can fit into any of the existing boxes
    bool found = false;
    for(int i = 0; i < n-1; ++i) {
        if(va[n-1] <= vb[i]) {
            cout << vb[i] << endl;
            found = true;
            break;
        }
    }

    // If no suitable box was found, check if the next larger box would work
    if(!found && va[n-1] <= vb[n-2]) {
        cout << vb[n-2] << endl;
    } else if(!found) {
        cout << "-1" << endl;
    }

    return 0;
}