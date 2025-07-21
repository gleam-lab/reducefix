#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 1; i < n; ++i)
        cin >> vb[i];

    // Sort both arrays in descending order
    sort(va.begin(), va.end(), greater<>());
    sort(vb.begin(), vb.end(), greater<>());

    // Check if it's possible to place all toys in separate boxes
    for (int i = 0; i < n - 1; ++i) {
        if (va[i] > vb[i]) {
            // If current toy cannot fit in the current box, check next box
            continue;
        }

        // If current toy fits in the current box, check next toy
        continue;
    }

    // If all toys fit in separate boxes, output the size of the last box
    cout << va.back() << endl;

    // If it's not possible to place all toys in separate boxes, output -1
    return 0;
}