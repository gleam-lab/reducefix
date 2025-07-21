#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Check if the largest toy fits into any of the existing boxes
    for (int i = 0; i < n - 1; i++) {
        if (va[n - 1] <= vb[i]) {
            cout << va[n - 1] << endl;
            return 0;
        }
    }

    // If the largest toy does not fit into any existing box,
    // then the new box must have a size at least as large as the largest toy
    cout << va[n - 1] << endl;

    return 0;
}