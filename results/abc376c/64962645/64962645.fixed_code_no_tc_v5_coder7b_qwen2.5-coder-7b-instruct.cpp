#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);

    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }

    // Sort the toys and boxes in descending order
    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end(), greater<int>());

    // Initialize the minimum box size needed
    int minBoxSize = -1;

    // Iterate through the toys and check if we can place them in the current box
    for (int i = 0; i < n; i++) {
        if (i < n - 1 && va[i] > vb[i]) {
            minBoxSize = max(minBoxSize, va[i]);
        } else if (i == n - 1) {
            minBoxSize = max(minBoxSize, va[i]);
        }
    }

    cout << minBoxSize << endl;

    return 0;
}