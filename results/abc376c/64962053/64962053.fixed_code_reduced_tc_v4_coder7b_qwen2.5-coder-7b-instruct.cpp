#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n);
    for (int i = 0; i < n; ++i) cin >> va[i];
    for (int i = 0; i < n - 1; ++i) cin >> vb[i];

    // Sort both arrays
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Check if the largest toy can fit in any of the available boxes
    bool found = false;
    for (int i = 0; i < n - 1; ++i) {
        if (va[n - 1] <= vb[i]) {
            cout << vb[i] << endl;
            found = true;
            break;
        }
    }

    // If no suitable box was found, check if the largest toy fits in a new box
    if (!found && va[n - 1] <= vb[n - 2]) {
        cout << va[n - 1] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}