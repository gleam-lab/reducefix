#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n);
    
    // Read input sizes
    for (int i = 0; i < n; i++)
        cin >> va[i];
    for (int i = 0; i < n - 1; i++)
        cin >> vb[i];

    // Sort the arrays
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Check if there is enough space in the boxes
    bool feasible = true;
    for (int i = 0; i < n; i++) {
        if (i >= n - 1 || vb[i] < va[i]) {
            feasible = false;
            break;
        }
    }

    // If not feasible, output -1
    if (!feasible) {
        cout << "-1" << endl;
        return 0;
    }

    // Find the minimum box size
    int min_box_size = *max_element(va.begin(), va.end());
    cout << min_box_size << endl;

    return 0;
}