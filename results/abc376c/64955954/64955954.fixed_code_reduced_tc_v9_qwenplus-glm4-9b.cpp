#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    // Sort both vectors in descending order
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());

    // Initialize the box index to 0
    int bx = 0;

    // Iterate through each toy
    for (int i = 0; i < n; i++) {
        // Find the smallest box that can accommodate the current toy
        while (bx < n - 1 && vb[bx] < va[i]) {
            bx++;
        }

        // If no box can accommodate the toy, output -1 and exit
        if (vb[bx] < va[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // If all toys are accommodated, output the size of the last used box
    cout << vb[bx] << endl;
    return 0;
}