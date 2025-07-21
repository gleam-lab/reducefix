#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    // Sort the sizes of toys and boxes in descending order
    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end(), greater<int>());

    // Find the maximum toy size which is smaller than or equal to the largest box size
    for (int i = 0; i < n - 1; ++i) {
        if (va[i] > vb[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // The minimum box size required to store all toys
    cout << va[n - 1] << endl;

    return 0;
}